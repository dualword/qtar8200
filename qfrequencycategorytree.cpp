#include <QMessageBox>
#include <QMouseEvent>
#include "qfrequencycategorytree.h"

QFrequencyCategoryTree::QFrequencyCategoryTree(QWidget *parent) : QTreeWidget(parent)
{

}

void QFrequencyCategoryTree::mousePressEvent(QMouseEvent *event)
{
  clearSelection();
  QTreeView::mousePressEvent(event);
}
