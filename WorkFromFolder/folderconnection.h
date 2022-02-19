#ifndef FOLDERCONNECTION_H
#define FOLDERCONNECTION_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QByteArray>
#include <QTimer>

namespace Ui {
class FolderConnection;
}

class FolderConnection : public QWidget
{
    Q_OBJECT

public:
    explicit FolderConnection(QWidget *parent = nullptr);
    ~FolderConnection();

    void parseFiles();

private slots:
    void on_chooseFolder_clicked();

    void on_exitButton_clicked();
    void on_runButton_clicked(bool checked);

signals:
    void sendDirPath(QString dirPath);
    void sendPlaneData(QString planeData);
    void unblur();

private:
    Ui::FolderConnection *ui;
    QString path;
};

#endif // FOLDERCONNECTION_H
