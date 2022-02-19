#include "maplayer.h"

MapLayer::MapLayer()
{

}

QRectF MapLayer::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void MapLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
