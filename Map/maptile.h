#ifndef MAPTILE_H
#define MAPTILE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QByteArray>

class MapTile
{
public:
    MapTile(int x, int y, double lon, double lat, QByteArray tileData);

    QPixmap getTile();
    QPoint getCoordinates();
    int x();
    int y();

private:
    QPoint coordinates;
    double lon, lat;
    QPixmap tile;
};

#endif // MAPTILE_H
