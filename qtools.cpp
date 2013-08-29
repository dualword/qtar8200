#include <QEventLoop>
#include "qtools.h"

qtools::qtools()
{
}

void qtools::sleep(int msec)
{
  QEventLoop loop;
  QTimer::singleShot(1000,&loop,SLOT(quit()));
  loop.exec();
}

void qtools::message(QString msg)
{
  QMessageBox msgBox;
  msgBox.setText(msg);
  msgBox.exec();
}
