#include "folderworker.h"

void FolderWorker::setUpFolderDir(QString folderDir)
{
    this->folderDir.setPath(folderDir);

    if (this->folderDir.exists()) {
        timer = new QTimer();
        timer->setInterval(10000);
        timer->start();

        connect(timer, &QTimer::timeout, this, &FolderWorker::parseFiles);

        emit sendPointer(this);
    } else {

    }
}

void FolderWorker::parseFiles()
{
    if (folderDir.exists())
    {
        folderDir.setFilter(QDir::Files | QDir::AllDirs);
        folderDir.setSorting(QDir::Name | QDir::Reversed);
        QFileInfoList list = folderDir.entryInfoList();

        for(int i = 0; i<list.size();i++)
        {
            QFileInfo info = list[i];
            QString name = info.absoluteFilePath();

            QFile fileIn(name);

            if (fileIn.open(QIODevice::ReadOnly)) {
                while (!fileIn.atEnd())
                {
                    emit sendPlaneData(fileIn.readLine());
//                    qDebug() << fileIn.readLine();
                    int i = 1000000;

                    while (i > 0) {
                        i--;
                    }
                }
            }
        }
    } else {
        //emit error
    }
}
