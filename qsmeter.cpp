#include <QGraphicsItem>
#include <math.h>
#include "qsmeter.h"

// Constructor
QSMeter::QSMeter(QWidget *parent) : QGraphicsView(parent)
{
  DrawInitialState();
}

// Destructor
QSMeter::~QSMeter()
{

}

// Draw initial state
void QSMeter::DrawInitialState()
{

  // Init scene
  QGraphicsScene* scene = new QGraphicsScene();
  setScene(scene);
  scene->setSceneRect(0,0,160,80);
  // Draw background
  BackgroundImage = QPixmap(":/smeter.png");
  QGraphicsPixmapItem* item = new QGraphicsPixmapItem(BackgroundImage);
  scene->addItem(item);
  // Draw needle
  setRenderHint(QPainter::Antialiasing);
  Needle = scene->addLine(80,80-33,80,80-105-33);

}

void QSMeter::SetDb(float dB)
{
  // Normalize db range.
  if (dB < -54) dB = -54;
  if (dB > 30) dB = 30;
  // Convert to angle.
  float angle = 1.0966*dB+100.934;
  // Get canvas coordinates from angle.
  Needle->setLine(AngleToLine(angle));
}

QLineF QSMeter::AngleToLine(float angle)
{
  float rad;
  float s,c;
  const double pi = 3.14159265;
  QPoint origin;
  QPoint lookat;
  int pixmap_half_width = BackgroundImage.width()/2;
  int pixmap_height = BackgroundImage.height();
  const int needle_length = 105;
  // Distance from pixmap bottom to fix point of needle.
  const int needle_vertex = 33;
  // numerical protection: 0.0 < angle < 180.0
  if (!(0.0 < angle) || !(angle < 180.0))
  {
    angle = 90.0;
  }
  if (angle <= 90.0)
  {
    // convert angle to radians
    rad = pi * angle / 180.0;
    // calculate sin and cos
    s = sin (rad);
    c = cos (rad);
    lookat.setX( pixmap_half_width - needle_vertex * sqrt (1/(s*s) - 1) );
    lookat.setY( pixmap_height );
    origin.setX( lookat.x() - (needle_length - needle_vertex/s) * c );
    origin.setY( pixmap_height + needle_vertex - needle_length * s );
  }
  else
  {
    angle = angle - 90.0;
    /* convert angle to radians */
    rad = pi * angle / 180.0;
    /* calculate sin and cos */
    s = sin (rad);
    c = cos (rad);
    lookat.setX( pixmap_half_width + needle_vertex * sqrt (1/(c*c) - 1) );
    lookat.setY( pixmap_height );
    origin.setX( lookat.x() + (needle_length - needle_vertex/c) * s );
    origin.setY( pixmap_height + needle_vertex - needle_length * c );
  }
  // Put two points in line vector and return the result.
  QLineF result;
  result.setPoints(origin,lookat);
  return result;
}
