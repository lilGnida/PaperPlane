#include "planeprocessor.h"
#include "network/networkcontroller.h"
#include "PlaneProcessor/planegraphicsobject.h"
#include <QDebug>

PlaneProcessor::PlaneProcessor(QObject *parent) : parent(parent)
{

}

void PlaneProcessor::setFolderWorker(FolderWorker *folderWorker)
{
    this->folderWorker = folderWorker;
    qDebug() << "folderWorker pointer set";
}

void PlaneProcessor::processPlaneData(QString planeData)
{
    QString icao = planeData.mid(planeData.indexOf("ICAO24: 0x") + 10, 6);
    QString callName = planeData.mid(planeData.indexOf("IDENT:") + 7, 6);
    QString mode3A = planeData.mid(planeData.indexOf("MODE3A:") + 8, 4);
    double lat = planeData.midRef(planeData.indexOf("LAT:") + 5, 7).toDouble();
    double lon = planeData.midRef(planeData.indexOf("LON:") + 5, 7).toDouble();
    double elv = planeData.midRef(planeData.indexOf("ELV:") + 5, 7).toDouble();

    if (planeBuffer.contains(icao)) {
        planeBuffer[icao]->pushBackCoordinates(QPointF(lat, lon));
    } else {
        PlaneGraphicsObject *planeGraphicsObject = new PlaneGraphicsObject();
        planeGraphicsObject->pushBackCoordinates(QPointF(lat, lon));
        planeGraphicsObject->setPos(QPointF((lon + 180) * 256 / 360, (90 - lat) * 256 / 360));
        qDebug() << (QPointF((lon + 180) * 256 / 360, (90 - lat) * 256 / 360));

        planeBuffer.insert(icao, planeGraphicsObject);

        emit sendPlaneToScene(planeGraphicsObject);
    }
}
