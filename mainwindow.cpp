#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    blurMainWindow = new QGraphicsBlurEffect(this);
    blurMainWindow->setBlurRadius(15);
    blurMainWindow->setEnabled(false);
    this->setGraphicsEffect(blurMainWindow);

    ui->setupUi(this);
    ui->graphicsView->setMouseTracking(true);

    this->controller = new Controller(this);
    this->networkController = new NetworkController(this);
    this->folderConnectionController = new FolderConnectionController(this);
    this->dbConnectorController = new DataBaseConnectorController(this);
    this->scene = new SceneController(ui->graphicsView);

    this->mapLayer = new MapLayer();
    this->civilPlanesLayer = new MapLayer();
    this->militaryPlanesLayer = new MapLayer();

    this->mapLayer->setZValue(0);
    this->civilPlanesLayer->setZValue(1);
    this->militaryPlanesLayer->setZValue(2);

    scene->addItem(mapLayer);
    scene->addItem(civilPlanesLayer);
    scene->addItem(militaryPlanesLayer);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    emit controller->loadMap(dbPath, zScale);
    emit controller->loadMap(dbWithCitiesPath, zScale);
    ui->graphicsView->scale(4, 4);

    connect(ui->graphicsView, &MapViewController::scaleValueChanged, this, &MainWindow::scaleValueChanged);
    connect(ui->graphicsView, &MapViewController::dragInAction, this, &MainWindow::dragInAction);

    sideBarAnimation = new QPropertyAnimation(ui->sideHiddenMenuFrame, "minimumWidth");
    sideBarAnimation->setDuration(250);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Controller *MainWindow::getController()
{
    return controller;
}

NetworkController *MainWindow::getNetworkController()
{
    return networkController;
}

FolderConnectionController *MainWindow::getFolderConnectionController()
{
    return folderConnectionController;
}

void MainWindow::addItemToScene(QGraphicsItem *item)
{
    item->setParentItem(mapLayer);
    scene->addItem(item);
}

void MainWindow::addPlaneToScene(QGraphicsObject *obj)
{
    obj->setParentItem(civilPlanesLayer);
    scene->addItem(obj);
}

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

void MainWindow::blur()
{
    blurMainWindow->setEnabled(false);
}

void MainWindow::clearScene()
{
    scene->removeItem(mapLayer);
    delete mapLayer;
    mapLayer = new MapLayer();
    mapLayer->setZValue(0);
    scene->addItem(mapLayer);

    emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
}

void MainWindow::dragInAction()
{
    clearScene();
}

void MainWindow::printPlane(Plane *plane)
{
    qDebug() << plane->getIcao();
}

void MainWindow::scaleValueChanged(double scaleValue)
{
    if (scaleValue >= pow(2, zScale) && zScale < 9) {
        zScale++;
        ui->verticalSlider->setValue(zScale);
    }
    else if (scaleValue <= pow(2, zScale - 1) && zScale > 1) {
        zScale--;
        ui->verticalSlider->setValue(zScale);
    } else {
        return;
    }

    clearScene();
}

void MainWindow::on_zoomInButton_clicked()
{
    if (zScale < 9) {
        ui->graphicsView->scale(2, 2);
        zScale++;
        ui->verticalSlider->setValue(zScale);

        clearScene();
    }
}


void MainWindow::on_zoomOutButton_clicked()
{
    if (zScale > 3) {
        ui->graphicsView->scale(0.5, 0.5);
        zScale--;
        ui->verticalSlider->setValue(zScale);

        clearScene();
    }
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    if (value > zScale) {
        on_zoomInButton_clicked();
    }
    if (value < zScale) {
        on_zoomOutButton_clicked();
    }
}


void MainWindow::on_addNewConnection_triggered()
{
    networkController->showNewUdpConnectionWindow();
    blurMainWindow->setEnabled(true);
}


void MainWindow::on_reloadMap_triggered()
{
    clearScene();
}


void MainWindow::on_connectDB_triggered()
{
    dbConnectorController->showDataBaseConnectionWindow();
    blurMainWindow->setEnabled(true);
}


void MainWindow::on_manageConnections_triggered()
{
    networkController->showConnectionManagmentWindow();
    blurMainWindow->setEnabled(true);
}


void MainWindow::on_sideBarMenuButton_clicked()
{
    if (ui->sideHiddenMenuFrame->width() < 250) {
        sideBarAnimation->setStartValue(0);
        sideBarAnimation->setEndValue(250);
        sideBarAnimation->start();
    } else {
        sideBarAnimation->setStartValue(250);
        sideBarAnimation->setEndValue(0);
        sideBarAnimation->start();
    }
}


void MainWindow::on_workFromFolder_triggered()
{
    folderConnectionController->showFolderConnection();
    blurMainWindow->setEnabled(true);
}

