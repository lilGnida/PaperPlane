#include "Map/controller.h"
#include <mainwindow.h>
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

Controller::Controller(MainWindow *wnd)
    : window(wnd)
{
    mapWorker = new MapWorker;
    modelThread = new QThread;

    //connect
    connect(this, &Controller::loadMap, mapWorker, &MapWorker::loadMap);
    connect(this, &Controller::updateMap, mapWorker, &MapWorker::updateMap);

    connect(mapWorker, &MapWorker::sendItemToScene, window, &MainWindow::addItemToScene);

    mapWorker->moveToThread(modelThread);
    modelThread->start();
}

Controller::~Controller() {
    modelThread->quit();
    modelThread->wait();
}
