#ifndef FOLDERWORKER_H
#define FOLDERWORKER_H

#include <QThread>
#include <QWidget>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QFileInfo>
#include <QDir>

class FolderWorker: public QObject
{
    Q_OBJECT
public:

private:
    QDir folderDir;
    QTimer *timer;

public slots:
    void setUpFolderDir(QString folderDir);
    void parseFiles();

signals:
    void sendPlaneData(QString);
    void sendPointer(FolderWorker *pointer);
};

#endif // FOLDERWORKER_H
