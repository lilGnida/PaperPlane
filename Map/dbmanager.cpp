#include "dbmanager.h"

DBManager::DBManager(const QString& path)
{   
    if (path != "") {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);

        QSqlTableModel *DB_tableModel = new QSqlTableModel(nullptr, db);

        DB_tableModel->setTable("map");
        DB_tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        DB_tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("x"));
        DB_tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("y"));
        DB_tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("v"));
        DB_tableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("c"));
        DB_tableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("s"));
        DB_tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("h"));
        DB_tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("d"));
        DB_tableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("b"));
    }
}

DBManager::~DBManager()
{
    if (db.isOpen()) {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

//void DBManager::insertDataInDB(QStringList data)
//{
//    QSqlQuery query;
//    query.prepare("INSERT INTO hohloLodki VALUES (:CentralizedNumber,:ObjectID,:Name,:StateID,:UnitIdRegistered,:DateLastEvent)");
//    query.bindValue(":CentralizedNumber", data.at(0));
//    query.bindValue(":ObjectID", data.at(1));
//    query.bindValue(":Name", data.at(2));
//    query.bindValue(":StateID", data.at(3));
//    query.bindValue(":UnitIdRegistered", data.at(4));
//    query.bindValue(":DateLastEvent", data.at(5));
//    query.exec();

//}

QString DBManager::getDBpath()
{
    return db.databaseName();
}

bool DBManager::getDBconnectionStatus()
{
    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return false;
    } else {
        qDebug() << "Database: connection ok";
        return true;
    }
}

void DBManager::loadTiles()
{
    QSqlQuery query(db);
    query.prepare("SELECT x, y, h, d, b FROM t");

    tiles.clear();
    tilesCount = 0;

    if (query.exec()) {
        while (query.next()) {
            MapTile tile(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toDouble(), query.value(3).toDouble(), query.value(4).toByteArray());
            tiles.append(tile);
            tilesCount++;
        }
    } else {
        qDebug() << "Error: Tiles load failed";
    }
}

void DBManager::loadTilesIn(QRect visibleRect)
{
    QSqlQuery query(db);
    QStringList x, y;

    for (int i = visibleRect.x(); i < visibleRect.x() + visibleRect.width(); i++) {
        x << QString::number(i);
    }

    for (int i = visibleRect.y(); i < visibleRect.y() + visibleRect.height(); i++) {
        y << QString::number(i);
    }

    query.prepare(QString("SELECT x, y, h, d, b FROM t WHERE x IN (%1) AND y IN (%2)").arg(x.join(",")).arg(y.join(",")));

    tiles.clear();
    tilesCount = 0;

    if (query.exec()) {
        while (query.next()) {
            MapTile tile(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toDouble(), query.value(3).toDouble(), query.value(4).toByteArray());

            if (visibleRect.contains(tile.getCoordinates())) {
                tiles.append(tile);
                tilesCount++;
            }
        }
    } else {
        qDebug() << "Error: Tiles load failed";
    }
}

void DBManager::disconnect()
{
    if (db.isOpen()) {
        qDebug() << "DataBase: Disconnected from " << db.databaseName();
        db.close();
    } else {
        qDebug() << "Error: disconnection from " << db.databaseName() << " failed";
    }
}

QList <MapTile> DBManager::getTiles()
{
    return tiles;
}

MapTile *DBManager::getTileAt(int pos)
{
    return &tiles[pos];
}

int DBManager::getTilesCount()
{
    return tilesCount;
}
