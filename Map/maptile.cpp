#include "Map/maptile.h"

MapTile::MapTile(int x, int y, double lon, double lat, QByteArray tileData)
{
    coordinates.setX(x);
    coordinates.setY(y);
    this->lon = lon;
    this->lat = lat;
    tile.loadFromData(tileData);
}

QPixmap MapTile::getTile()
{
    return tile;
}

QPoint MapTile::getCoordinates()
{
    return coordinates;
}

int MapTile::x()
{
    return coordinates.x();
}

int MapTile::y()
{
    return coordinates.y();
}
