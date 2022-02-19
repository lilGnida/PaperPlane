#include "Map/controller.h"
#include <mainwindow.h>
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

Controller::Controller(MainWindow *wnd)
    : window(wnd)
{
    mapWorker = new MapWorker;
//    modelThread = new QThread;

    planeProcessor = new PlaneProcessor(this);
    planeProcessorThread = new QThread;

    //connect
    connect(this, &Controller::loadMap, mapWorker, &MapWorker::loadMap);
    connect(this, &Controller::updateMap, mapWorker, &MapWorker::updateMap);

    connect(planeProcessor, &PlaneProcessor::sendPlane, window, &MainWindow::printPlane);
    connect(planeProcessor, &PlaneProcessor::sendPlaneToScene, window, &MainWindow::addPlaneToScene);

    connect(mapWorker, &MapWorker::sendItemToScene, window, &MainWindow::addItemToScene);

//    mapWorker->moveToThread(modelThread);
//    modelThread->start();

    planeProcessor->moveToThread(planeProcessorThread);
    planeProcessorThread->start();
}

Controller::~Controller() {
//    modelThread->quit();
//    modelThread->wait();

    planeProcessorThread->quit();
    planeProcessorThread->wait();
}

MapWorker *Controller::getMapWorker()
{
    return mapWorker;
}

PlaneProcessor *Controller::getPlaneProcessor()
{
    return planeProcessor;
}
