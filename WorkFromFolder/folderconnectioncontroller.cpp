#include "folderconnectioncontroller.h"
#include "mainwindow.h"
#include "PlaneProcessor/planeprocessor.h"
#include "Map/mapWorker.h"

FolderConnectionController::FolderConnectionController(MainWindow *wnd)
  :window(wnd)
{
    folderConnection = new FolderConnection;
    folderWorker = new FolderWorker();
    folderWorkerThread = new QThread();

    connect(folderConnection, &FolderConnection::unblur, this, &FolderConnectionController::unblurMainWindow);
    connect(folderConnection, &FolderConnection::sendDirPath, folderWorker, &FolderWorker::setUpFolderDir);
    connect(folderWorker, &FolderWorker::sendPointer, window->getController()->getPlaneProcessor(), &PlaneProcessor::setFolderWorker);
    connect(folderWorker, &FolderWorker::sendPlaneData, window->getController()->getPlaneProcessor(), &PlaneProcessor::processPlaneData);

    folderWorker->moveToThread(folderWorkerThread);
    folderWorkerThread->start();
}

FolderConnectionController::~FolderConnectionController()
{
    folderWorkerThread->quit();
    folderWorkerThread->wait();
}

void FolderConnectionController::showFolderConnection()
{
    folderConnection->show();
}

void FolderConnectionController::unblurMainWindow()
{
    window->blur();
}

FolderWorker *FolderConnectionController::getFolderWorker()
{
    return folderWorker;
}
