#ifndef QFREQUENCYDATABASE_H
#define QFREQUENCYDATABASE_H

#include <string>
#include <vector>
#include <QTreeWidgetItem>
#include <QtSql/QSqlQueryModel>
#include "qrig.h"

class QFrequencyDatabase : public QSqlQueryModel
{

  Q_OBJECT

  public:

    /// POD structure for frequency category group data.
    struct category
    {
      category() : name(""), id(0), parent_id(0), tree_item(NULL){};
      std::string name;
      int id;
      int parent_id;
      QTreeWidgetItem* tree_item;
    };

    /// POD structure for frequency data.
    struct frequency
    {
      frequency() : description(""), mode(QRig::MODE_NONE), freq(""), attenuator(false), squelch(0),id_category(0),notes(""){};
      int id;
      std::string description;
      QRig::MODE mode;
      std::string freq;
      bool attenuator;
      int squelch;
      int id_category;
      std::string notes;
    };

    /// POD structure for log entry.
    struct logentry
    {
      std::string freq;
      QRig::MODE mode;
      std::string note;
      std::string time;
      std::string filename;
    };

    /// Collection of frequency categories.
    typedef std::vector<category*> categories;

    /// Collection of frequencies.
    typedef std::vector<frequency*> frequencies;

    /// Collection of log entries.
    typedef std::vector<logentry*> logentries;

    /// Constructor
    QFrequencyDatabase(QSqlDatabase* database, QObject *parent=0);

    /// Destructor
    ~QFrequencyDatabase();

    /// Get categories.
    categories GetCategories(int parent_category_id=0);

    /// Save a new category to database.
    /// \param category_data Category data to add.
    /// \return Returns id of new category. (= 0 on error).
    int CreateCategory(category* category_data);

    /// Save a new frequency to database.
    /// \param frequency_data Frequency data to add.
    /// \return Returns id of new frequency. (= 0 on error).
    int CreateFrequency(frequency* frequency_data);

    /// Get all frequencies for given category.
    /// \param category_id ID of category to get frequencies for.
    /// \return Returns a collection of frequencies for given category.
    frequencies GetFrequenciesForCategory(int category_id);

    /// Updates description text in database for frequency item with given id.
    bool UpdateDescription(int frequency_id, std::string text);

    /// Updates note text in database for frequency item with given id.
    bool UpdateNote(int frequency_id, std::string text);

    /// Logs reception of a frequency.
    bool Log(std::string freq, QRig::MODE mode, std::string filename);

    /// Gets all log entries.
    logentries GetLogEntries();

    /// Allocate a new frequency object.
    frequency* AllocFrequency(){ frequency* freq = new frequency; frequency_pool.push_back(freq); return freq; }

    /// Allocates a new logentry object.
    logentry* AllocLogEntry(){ logentry* log = new logentry; logentry_pool.push_back(log); return log; }

    /// Allocate a new category object.
    category* AllocCategory(){ category* cat = new category; category_pool.push_back(cat); return cat; }

  private:

    /// Database object.
    QSqlDatabase* db;
    /// Storage for allocated categories.
    categories category_pool;
    /// Storage for allocated frequencies.
    frequencies frequency_pool;
    /// Storage for allocated log entries.
    logentries logentry_pool;

};

#endif // QFREQUENCYDATABASE_H
