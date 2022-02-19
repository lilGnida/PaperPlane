#ifndef PLANEPROCESSOR_H
#define PLANEPROCESSOR_H

#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QMap>
#include "PlaneProcessor/plane.h"
#include "PlaneProcessor/planegraphicsobject.h"

class FolderWorker;

class PlaneProcessor: public QObject
{
    Q_OBJECT

public:
    PlaneProcessor(QObject *parent);

    void setFolderWorker(FolderWorker *folderWorker);

private:
    QObject *parent = nullptr;
//    QMap <QString, Plane> planeBuffer;
    QMap <QString, PlaneGraphicsObject*> planeBuffer;
    FolderWorker *folderWorker = nullptr;

public slots:
    void processPlaneData(QString planeData);

signals:
    void sendPlane(Plane *plane);
    void sendPlaneToScene(PlaneGraphicsObject *obj);
};

#endif // PLANEPROCESSOR_H
