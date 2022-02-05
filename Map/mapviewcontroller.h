#ifndef MAPVIEWCONTROLLER_H
#define MAPVIEWCONTROLLER_H

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QtWidgets>
#include <QWidget>
#include <QRectF>
#include <QGestureEvent>

class MapViewController: public QGraphicsView
{
    Q_OBJECT

public:
    MapViewController(QWidget* parent = 0);
    QRect getVisibleRect(float zScale);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    virtual void wheelEvent(QWheelEvent *event);

private:
    double scaleValue;
    bool pressed;
    bool dragging;

signals:
    void scaleValueChanged(double scaleValue);
    void dragInAction();
};

#endif // MAPVIEWCONTROLLER_H
