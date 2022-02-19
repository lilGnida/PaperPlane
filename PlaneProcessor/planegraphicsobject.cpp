#include "PlaneProcessor/planegraphicsobject.h"

PlaneGraphicsObject::PlaneGraphicsObject()
{
    //    trackCoordinates = coordinates;
}

void PlaneGraphicsObject::pushBackCoordinates(QPointF point)
{
    trackCoordinates.push_back(point);
}

QRectF PlaneGraphicsObject::boundingRect() const
{
    float x_min = 0, y_min = 0, x_max = 0, y_max = 0;

    for (int i = 0; i < trackCoordinates.count(); i++) {
        QPointF point = trackCoordinates[i];

        if (point.x() < x_min) {
            x_min = point.x();
        } else if (point.x() > x_max) {
            x_max = point.x();
        } else if (point.y() < y_min) {
            y_min = point.y();
        } else if (point.y() > y_max) {
            y_max = point.y();
        }
    }

    return QRectF(x_min, y_min, x_max, y_max);
}

void PlaneGraphicsObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::red,1,Qt::SolidLine,Qt::RoundCap);
    painter->setPen(pen);

    QPointF *coordinates = new QPointF[trackCoordinates.count()];

    for (int i = 0; i < trackCoordinates.count(); i++) {
        coordinates[i] = trackCoordinates.at(i);
    }

    painter->drawPolyline(coordinates, trackCoordinates.count());

    delete[] coordinates;

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
