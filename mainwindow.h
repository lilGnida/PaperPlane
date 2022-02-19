#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include "Map/controller.h"
#include "Map/mapviewcontroller.h"
#include "Map/maplayer.h"
#include "network/networkcontroller.h"
#include "DataBase/databaseconnectorcontroller.h"
#include "WorkFromFolder/folderconnectioncontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Controller *getController();
    NetworkController *getNetworkController();
    FolderConnectionController *getFolderConnectionController();

    Ui::MainWindow *getUi() const;

    void blur();
    void clearScene();

private:
    Ui::MainWindow *ui;
    SceneController *scene;
    Controller *controller = nullptr;
    NetworkController *networkController = nullptr;
    FolderConnectionController *folderConnectionController = nullptr;
    DataBaseConnectorController *dbConnectorController = nullptr;
    QString dbPath = "/Users/nikitaandreev/Desktop/Programming/Quadrocopter/LandMap/z%1/0/0/0.0.sqlitedb";
    QString dbWithCitiesPath = "/Users/nikitaandreev/Desktop/Programming/Quadrocopter/Both/z%1/0/0/0.0.sqlitedb";

    int zScale = 3;

    MapLayer *mapLayer = nullptr;
    MapLayer *civilPlanesLayer = nullptr;
    MapLayer *militaryPlanesLayer = nullptr;

    QPropertyAnimation *sideBarAnimation;
    QGraphicsBlurEffect *blurMainWindow;
    bool mainWindowIsBlured = false;

public slots:
    void addItemToScene(QGraphicsItem *item);
    void addPlaneToScene(QGraphicsObject *obj);
    void scaleValueChanged(double scaleValue);
    void dragInAction();

    void printPlane(Plane *plane);

private slots:
    void on_zoomInButton_clicked();
    void on_zoomOutButton_clicked();
    void on_verticalSlider_valueChanged(int value);
    void on_addNewConnection_triggered();
    void on_reloadMap_triggered();
    void on_connectDB_triggered();
    void on_manageConnections_triggered();
    void on_sideBarMenuButton_clicked();
    void on_workFromFolder_triggered();
};
#endif // MAINWINDOW_H
