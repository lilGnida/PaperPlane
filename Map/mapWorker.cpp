#include "mapWorker.h"

void MapWorker::loadMap(QString dbPath, int zScale)
{
    DBManager *dataBase = new DBManager(dbPath.arg(zScale));
    dataBase->getDBconnectionStatus();
    dataBase->loadTiles();

    for (int i = 0; i < dataBase->getTiles().count(); i++) {
        MapTile mapTile = dataBase->getTiles().at(i);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(mapTile.getTile());
        item->setScale(1 / pow(2, zScale - 1));
        item->setPos(mapTile.x() * (256 / pow(2, zScale - 1)), mapTile.y() * (256 / pow(2, zScale - 1)));

        emit sendItemToScene(item);
    }
//    dataBase->disconnect();
    delete dataBase;
}

void MapWorker::updateMap(QString dbPath, QRect visibleRect, int zScale)
{
    DBManager *dataBase = new DBManager(dbPath.arg(zScale));
    dataBase->getDBconnectionStatus();
    dataBase->loadTilesIn(visibleRect);

    for (int i = 0; i < dataBase->getTiles().count(); i++) {
        MapTile mapTile = dataBase->getTiles().at(i);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(mapTile.getTile());
        item->setScale(1 / pow(2, zScale - 1));
        item->setPos(mapTile.x() * (256 / pow(2, zScale - 1)), mapTile.y() * (256 / pow(2, zScale - 1)));

        emit sendItemToScene(item);
    }
//    dataBase->disconnect();
    delete dataBase;
}

////Отображение координат в статусбаре
//void MapWorker::mousePositionChanged(QPointF point)
//{
//    double lon = point.x() / (256 * pow(4, zScale - 2));
//    double lat = point.y() / (256 * pow(4, zScale - 2));
//    lon *= 360;
//    lat *= 180;

//    QString strSphereCoordinates = "";

//    if (lon > 180) {
//        sphereCoordinates.setX(lon - 180); //восточная долгота

//        if (lat > 90) {
//            sphereCoordinates.setY(lat - 90); //северная широта

//            strSphereCoordinates = QString::number(sphereCoordinates.y()) + " ю.ш.  " + QString::number(sphereCoordinates.x()) + " в.д.";
//        } else {
//            sphereCoordinates.setY(90 - lat); //южная широта

//            strSphereCoordinates = QString::number(sphereCoordinates.y()) + " с.ш.  " + QString::number(sphereCoordinates.x()) + " в.д.";
//        }
//    } else {
//        sphereCoordinates.setX(180 - lon); //западная долгота

//        if (lat > 90) {
//            sphereCoordinates.setY(lat - 90); //северная широта

//            strSphereCoordinates = QString::number(sphereCoordinates.y()) + " ю.ш.  " + QString::number(sphereCoordinates.x()) + " з.д.";
//        } else {
//            sphereCoordinates.setY(90 - lat); //южная широта

//            strSphereCoordinates = QString::number(sphereCoordinates.y()) + " с.ш.  " + QString::number(sphereCoordinates.x()) + " з.д.";
//        }
//    }


//    ui->statusbar->showMessage(strSphereCoordinates);
//}
