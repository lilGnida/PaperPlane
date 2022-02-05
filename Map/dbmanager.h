#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QList>
#include <QPixmap>
#include "Map/maptile.h"

class DBManager
{
public:
    DBManager(const QString& path);
    ~DBManager();

    QSqlTableModel *DB_tableModel;

//    void insertDataInDB(QStringList data);

    QString getDBpath();
    bool getDBconnectionStatus();
    void loadTiles();
    void loadTilesIn(QRect visibleRect);
    void disconnect();
    QList <MapTile> getTiles();
    MapTile* getTileAt(int pos);
    int getTilesCount();

private:
    QSqlDatabase db;
    QList <MapTile> tiles;
    int tilesCount = 0;

};

#endif // DBMANAGER_H
