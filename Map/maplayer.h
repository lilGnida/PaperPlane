#ifndef MAPLAYER_H
#define MAPLAYER_H

#include <QGraphicsItem>

class MapLayer : public QGraphicsItem
{
public:
    MapLayer();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MAPLAYER_H
