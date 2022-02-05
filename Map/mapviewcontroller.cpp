#include "Map/mapviewcontroller.h"
#include <QDebug>

MapViewController::MapViewController(QWidget *parent) : QGraphicsView(parent)
{

}

QRect MapViewController::getVisibleRect(float zScale)
{
    QRectF visibleRect = mapToScene(viewport()->geometry()).boundingRect();

    int num = 256 / pow(2, zScale - 1);

    int x = trunc(visibleRect.x() / num - 2);
    int y = trunc(visibleRect.y() / num - 2);
    int width = ceil(visibleRect.width() / num + 4);
    int height = ceil(visibleRect.height() / num + 4);

    QRect visibleRectInDBCoordinates(x < 0 ? 0 : x, y < 0 ? 0 : y, width, height);

    return visibleRectInDBCoordinates;
}

void MapViewController::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.1;
    scaleValue = QGraphicsView::transform().m11();

    if (event->delta() > 0) {
        scale(scaleFactor, scaleFactor);
        emit scaleValueChanged(scaleValue);
    } else {
        scale(1 / scaleFactor, 1 / scaleFactor);
        emit scaleValueChanged(scaleValue);
    }
}

void MapViewController::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        pressed=true;
    }
    QGraphicsView::mousePressEvent(event);
}

void MapViewController::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && pressed)
    {
        dragging=true;
//        emit dragInAction();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void MapViewController::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && pressed) {
        pressed = false;
        if (dragging)
        {
            dragging = false;
            emit dragInAction();
        }
        else
        {
            // plain mouse click
            // do something here
        }
    }
    QGraphicsView::mouseReleaseEvent(event);
}
