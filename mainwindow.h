#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include "Map/controller.h"
#include "Map/mapviewcontroller.h"
#include "network/networkcontroller.h"
#include "DataBase/databaseconnectorcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *getUi() const;

    void blur(bool blur);

private:
    Ui::MainWindow *ui;
    SceneController *scene;
    Controller *controller = nullptr;
    NetworkController *networkController = nullptr;
    DataBaseConnectorController *dbConnectorController = nullptr;
    QString dbPath = "/Users/nikitaandreev/Desktop/Programming/Quadrocopter/LandMap/z%1/0/0/0.0.sqlitedb";
    QString dbWithCitiesPath = "/Users/nikitaandreev/Desktop/Programming/Quadrocopter/Both/z%1/0/0/0.0.sqlitedb";

    int zScale = 3;

    QPropertyAnimation *sideBarAnimation;
    QGraphicsBlurEffect *blurMainWindow;
    bool mainWindowIsBlured = false;

public slots:
    void addItemToScene(QGraphicsPixmapItem *item);
    void scaleValueChanged(double scaleValue);
    void dragInAction();

private slots:
    void on_zoomInButton_clicked();
    void on_zoomOutButton_clicked();
    void on_verticalSlider_valueChanged(int value);
    void on_addNewConnection_triggered();
    void on_reloadMap_triggered();
    void on_connectDB_triggered();
    void on_manageConnections_triggered();
    void on_sideBarMenuButton_clicked();
};
#endif // MAINWINDOW_H
