#ifndef QTOOLS_H
#define QTOOLS_H

#include <QTimer>
#include <QString>
#include <QMessageBox>

class qtools
{
  public:
    qtools();
    static void sleep(int msec);
    static void message(QString msg);
};

#endif // QTOOLS_H
