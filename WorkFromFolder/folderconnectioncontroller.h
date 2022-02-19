#ifndef FOLDERCONNECTIONCONTROLLER_H
#define FOLDERCONNECTIONCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QMainWindow>
#include "WorkFromFolder/folderworker.h"
#include "WorkFromFolder/folderconnection.h"

class MainWindow;

class FolderConnectionController: public QObject
{
    Q_OBJECT

public:
    FolderConnectionController(MainWindow *wnd);
    ~FolderConnectionController();

    void showFolderConnection();
    void unblurMainWindow();

    FolderWorker *getFolderWorker();

private:
    FolderConnection *folderConnection = nullptr;
    MainWindow *window = nullptr;
    FolderWorker *folderWorker = nullptr;
    QThread *folderWorkerThread = nullptr;

public slots:

signals:

};

#endif // FOLDERCONNECTIONCONTROLLER_H
