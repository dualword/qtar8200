#ifndef QSMETER_H
#define QSMETER_H

// The math for converting the angles to canvas coordinates and all that fancy stuff was
// "borrowed" from grig (as is the background image).
// Thanks grig guys :)

#include <vector>
#include <QGraphicsView>
#include <QPoint>

/// Array of QPoint's to define a line (in our case).
typedef std::vector<QPoint> QPointVector;

class QSMeter : public QGraphicsView
{

  public:

    /// Constructor
    explicit QSMeter(QWidget *parent = 0);
  
    /// Destructor
    virtual ~QSMeter();

    /// Set meter to given dB.
    void SetDb(float dB);

  signals:
  
  public slots:

  private:

    /// Pixmap background image.
    QPixmap BackgroundImage;

    /// Needle of the signal meter.
    QGraphicsLineItem* Needle;

    /// Draws the background and initial state of the needle.
    ///
    /// This is called when the control gets created initially.
    void DrawInitialState();

    /** \brief Convert needle angle to canvas coordinates.
     *  \param angle The needle angle.
     *  \return Returns the converted coordinates.
     *
     *  This function converts the needle angle and calculates the two (x,y)
     *  cordinates necessary to draw the needle on the canvas. In order to do
     *  this the size of the canvas and information about the pixmap is needed.
     *  These are given byconstants in this file and must be adjustedin case
     *  of a new pixmap.
     *
     */
    QLineF AngleToLine(float angle);

  
};

#endif // QSMETER_H
