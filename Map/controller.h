#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QThread>
#include <QMainWindow>
#include "Map/mapWorker.h"
#include "PlaneProcessor/planeprocessor.h"

class MainWindow;

class Controller: public QObject
{
    Q_OBJECT

//    QThread *modelThread = nullptr;
    QThread *planeProcessorThread = nullptr;

public:
    Controller(MainWindow *wnd);
    ~Controller();

    MapWorker* getMapWorker();
    MainWindow* getMainWindow();
    PlaneProcessor* getPlaneProcessor();

private:
    MapWorker *mapWorker = nullptr;
    MainWindow *window = nullptr;
    PlaneProcessor *planeProcessor = nullptr;

public slots:

signals:
    void loadMap(QString dbPath, int zScale);
    void updateMap(QString dbPath, QRect visibleRect, int zScale);

};

#endif // CONTROLLER_H
