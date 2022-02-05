#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QThread>
#include <QMainWindow>
#include "Map/mapWorker.h"

class MainWindow;

class Controller: public QObject
{
    Q_OBJECT

    QThread *modelThread = nullptr;

public:
    Controller(MainWindow *wnd);
    ~Controller();

private:
    MapWorker *mapWorker = nullptr;
    MainWindow *window = nullptr;

public slots:

signals:
    void loadMap(QString dbPath, int zScale);
    void updateMap(QString dbPath, QRect visibleRect, int zScale);

};

#endif // CONTROLLER_H
