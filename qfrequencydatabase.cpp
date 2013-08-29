#include <assert.h>
#include <sstream>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include "qfrequencydatabase.h"

// Ctor.
QFrequencyDatabase::QFrequencyDatabase(QSqlDatabase* database, QObject *parent)
  : db(database)
{
  assert(db);
}

// Dtor.
QFrequencyDatabase::~QFrequencyDatabase()
{
  for (categories::iterator it = category_pool.begin(); it != category_pool.end(); ++it)
  {
    delete (*it);
  }
  for (frequencies::iterator it = frequency_pool.begin(); it != frequency_pool.end(); ++it)
  {
    delete (*it);
  }
}

// Get categories.
QFrequencyDatabase::categories QFrequencyDatabase::GetCategories(int parent_category_id)
{
  categories result;
  if (!db) return result;
  if (!db->isOpen()) return result;
  QSqlQuery query(*db);
  bool prepare_success = false;
  if (parent_category_id != 0)
  {
    prepare_success = query.prepare("SELECT * FROM category WHERE id_parent_category = :id");
    query.bindValue(":id",parent_category_id);
  }
  else
  {
    prepare_success = query.prepare("SELECT * FROM category WHERE id_parent_category = 0");
  }
  if (!prepare_success)
  {
    std::ostringstream errmsg;
    errmsg << "Error while running query: ";
    errmsg << std::endl;
    errmsg << query.lastQuery().toUtf8().constData();
    errmsg << std::endl << std::endl;
    errmsg << query.lastError().text().toUtf8().constData();
    QMessageBox msg(QMessageBox::Warning,"SQL Error",errmsg.str().c_str());
    msg.exec();
  }
  if (query.exec())
  {
    while (query.next())
    {
      category* new_category = AllocCategory();
      new_category->name = query.value(query.record().indexOf("name")).toString().toUtf8().constData();
      new_category->id = query.value(query.record().indexOf("id")).toInt();
      new_category->parent_id = query.value(query.record().indexOf("id_parent_category")).toInt();
      result.push_back(new_category);
    }
  }
  else
  {
    std::ostringstream errmsg;
    errmsg << "Error while running query: ";
    errmsg << std::endl;
    errmsg << query.lastQuery().toUtf8().constData();
    errmsg << std::endl << std::endl;
    errmsg << db->lastError().text().toUtf8().constData();
    QMessageBox msg(QMessageBox::Warning,"SQL Error",errmsg.str().c_str());
    msg.exec();
  }
  return result;
}

// Create a category.
int QFrequencyDatabase::CreateCategory(category* category_data)
{
  if (!db) return 0;
  if (!db->isOpen()) return 0;
  assert(category_data);
  QSqlQuery query(*db);
  if (!query.prepare("INSERT INTO category SET id_parent_category = :parent_id, name = :name"))
  {
    return 0;
  }
  query.bindValue(":parent_id",category_data->parent_id);
  query.bindValue(":name",category_data->name.c_str());
  if (!query.exec()) return 0;
  return query.lastInsertId().toInt();
}

// Save new frequency to database.
int QFrequencyDatabase::CreateFrequency(frequency* frequency_data)
{
  if (!db) return 0;
  if (!db->isOpen()) return 0;
  assert(frequency_data);
  QSqlQuery query(*db);
  if (!query.prepare(
    "INSERT INTO frequency SET description = :description, "
    "mode = :mode, frequency = :frequency, attenuator = :attenuator, "
    "squelch = :squelch, notes = :notes, id_category = :category"
  ))
  {
    return 0;
  }
  query.bindValue(":description",frequency_data->description.c_str());
  query.bindValue(":mode",static_cast<int>(frequency_data->mode));
  query.bindValue(":frequency",frequency_data->freq.c_str());
  query.bindValue(":attenuator",frequency_data->attenuator);
  query.bindValue(":squelch",frequency_data->squelch);
  query.bindValue(":notes",frequency_data->notes.c_str());
  query.bindValue(":category",frequency_data->id_category);
  if (!query.exec()) return 0;
  return query.lastInsertId().toInt();
}

// Get all frequencies for given category.
QFrequencyDatabase::frequencies QFrequencyDatabase::GetFrequenciesForCategory(int category_id)
{
  frequencies result;
  if (!db) return result;
  if (!db->isOpen()) return result;
  assert(category_id > 0);
  QSqlQuery query(*db);
  if (!query.prepare("SELECT * FROM frequency WHERE id_category = :category_id ORDER BY frequency ASC"))
  {
    std::ostringstream errmsg;
    errmsg << "Error while running query: ";
    errmsg << std::endl;
    errmsg << query.lastQuery().toUtf8().constData();
    errmsg << std::endl << std::endl;
    errmsg << db->lastError().text().toUtf8().constData();
    QMessageBox msg(QMessageBox::Warning,"SQL Error",errmsg.str().c_str());
    msg.exec();
    return result;
  }
  query.bindValue(":category_id",category_id);
  if (query.exec())
  {
    while (query.next())
    {
      frequency* new_frequency = AllocFrequency();
      new_frequency->attenuator = query.value(query.record().indexOf("attenuator")).toBool();
      new_frequency->description = query.value(query.record().indexOf("description")).toString().toUtf8().constData();
      new_frequency->freq = query.value(query.record().indexOf("frequency")).toString().toUtf8().constData();
      new_frequency->mode = static_cast<QRig::MODE>(query.value(query.record().indexOf("mode")).toInt());
      new_frequency->squelch = query.value(query.record().indexOf("squelch")).toInt();
      new_frequency->notes = query.value(query.record().indexOf("notes")).toString().toUtf8().constData();
      new_frequency->id = query.value(query.record().indexOf("id")).toInt();
      new_frequency->id_category = query.value(query.record().indexOf("id_category")).toInt();
      result.push_back(new_frequency);
    }
  }
  else
  {
    std::ostringstream errmsg;
    errmsg << "Error while running query: ";
    errmsg << std::endl;
    errmsg << query.lastQuery().toUtf8().constData();
    errmsg << std::endl << std::endl;
    errmsg << db->lastError().text().toUtf8().constData();
    QMessageBox msg(QMessageBox::Warning,"SQL Error",errmsg.str().c_str());
    msg.exec();
    return result;
  }
  return result;
}

// Updates description text in database for frequency item with given id.
bool QFrequencyDatabase::UpdateDescription(int frequency_id, std::string text)
{
  if (!db) return false;
  if (!db->isOpen()) return false;
  assert(frequency_id);
  QSqlQuery query(*db);
  if (!query.prepare("UPDATE frequency SET description = :description WHERE id = :id"))
  {
    return false;
  }
  query.bindValue(":description",text.c_str());
  query.bindValue(":id",frequency_id);
  return query.exec();
}

// Updates note text in database for frequency item with given id.
bool QFrequencyDatabase::UpdateNote(int frequency_id, std::string text)
{
  if (!db) return false;
  if (!db->isOpen()) return false;
  assert(frequency_id);
  QSqlQuery query(*db);
  if (!query.prepare("UPDATE frequency SET notes = :notes WHERE id = :id"))
  {
    return false;
  }
  query.bindValue(":notes",text.c_str());
  query.bindValue(":id",frequency_id);
  return query.exec();
}

// Logs reception of a frequency.
bool QFrequencyDatabase::Log(std::string freq, QRig::MODE mode, std::string filename)
{
  if (!db) return false;
  if (!db->isOpen()) return false;
  QSqlQuery query(*db);
  if (!query.prepare("INSERT INTO log SET time = NOW(), freq = :freq, mode = :mode, audiofile = :filename"))
  {
    return false;
  }
  query.bindValue(":freq", freq.c_str());
  query.bindValue("mode",mode);
  query.bindValue("filename",filename.c_str());
  return query.exec();
}

// Gets all log entries.
QFrequencyDatabase::logentries QFrequencyDatabase::GetLogEntries()
{
  logentries result;
  if (!db) return result;
  if (!db->isOpen()) return result;
  QSqlQuery query(*db);
  if (!query.prepare("SELECT * FROM log")) return result;
  if (query.exec())
  {
    while (query.next())
    {
      logentry* new_logentry = AllocLogEntry();
      new_logentry->freq = query.value(query.record().indexOf("freq")).toString().toUtf8().constData();
      new_logentry->mode = static_cast<QRig::MODE>(query.value(query.record().indexOf("mode")).toInt());
      new_logentry->time = query.value(query.record().indexOf("time")).toDateTime().toString().toUtf8().constData();
      new_logentry->note = query.value(query.record().indexOf("notes")).toString().toUtf8().constData();
      new_logentry->filename = query.value(query.record().indexOf("audiofile")).toString().toUtf8().constData();
      result.push_back(new_logentry);
    }
  }
  return result;
}
