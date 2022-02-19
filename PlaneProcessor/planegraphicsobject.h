#ifndef PLANEGRAPHICSOBJECT_H
#define PLANEGRAPHICSOBJECT_H

#include <QObject>
#include <QVector>
#include <QPointF>
#include <QGraphicsObject>
#include <QPainter>

class PlaneGraphicsObject : public QGraphicsObject
{
    Q_OBJECT

public:
    PlaneGraphicsObject();

    void pushBackCoordinates(QPointF point);

//    QPointF position();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
//    QObject *parent = nullptr;
    QVector <QPointF> trackCoordinates;
};

#endif // PLANEGRAPHICSOBJECT_H
