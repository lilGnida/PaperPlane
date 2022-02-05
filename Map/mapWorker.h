#ifndef MAPWORKER_H
#define MAPWORKER_H

#include <QThread>
#include <QWidget>
#include <QDebug>
#include <QGraphicsScene>
#include "Map/dbmanager.h"
#include "Map/scenecontroller.h"

class MapWorker: public QWidget
{
    Q_OBJECT

public:

private:
    DBManager *dataBase = nullptr;
    QPointF sphereCoordinates;

public slots:
    void loadMap(QString dbPath, int zScale);
    void updateMap(QString dbPath, QRect visibleRect, int zScale);

public slots:

signals:
    void sendItemToScene(QGraphicsPixmapItem *item);

};

#endif // MAPWORKER_H
