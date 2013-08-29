#ifndef QFREQUENCYCATEGORYTREE_H
#define QFREQUENCYCATEGORYTREE_H

#include <QTreeWidget>

class QFrequencyCategoryTree : public QTreeWidget
{
  Q_OBJECT

public:

  explicit QFrequencyCategoryTree(QWidget *parent = 0);

  virtual void mousePressEvent(QMouseEvent *event);

signals:
    
public slots:

};

#endif // QFREQUENCYCATEGORYTREE_H
