#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    ui->setupUi(this);
    ui->graphicsView->setMouseTracking(true);

    this->controller = new Controller(this);
    this->networkController = new NetworkController(this);
    this->dbConnectorController = new DataBaseConnectorController(this);
    this->scene = new SceneController(ui->graphicsView);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    emit controller->loadMap(dbPath, zScale);
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

void MainWindow::addItemToScene(QGraphicsPixmapItem *item)
{
    scene->addItem(item);
}

Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

void MainWindow::dragInAction()
{
    scene->clear();
    emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
}

void MainWindow::scaleValueChanged(double scaleValue)
{
    if (scaleValue >= pow(2, zScale) && zScale < 9) {
        zScale++;
        ui->verticalSlider->setValue(zScale);
        scene->clear();
        emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
        emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    }
    if (scaleValue <= pow(2, zScale - 1) && zScale > 1) {
        zScale--;
        ui->verticalSlider->setValue(zScale);
        scene->clear();
        emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
        emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    }
}

void MainWindow::on_zoomInButton_clicked()
{
    if (zScale < 9) {
        ui->graphicsView->scale(2, 2);
        zScale++;
        ui->verticalSlider->setValue(zScale);
        scene->clear();
        emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
        emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    }
}


void MainWindow::on_zoomOutButton_clicked()
{
    if (zScale > 3) {
        ui->graphicsView->scale(0.5, 0.5);
        zScale--;
        ui->verticalSlider->setValue(zScale);
        scene->clear();
        emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
        emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
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
}


void MainWindow::on_reloadMap_triggered()
{
    scene->clear();
    emit controller->updateMap(dbPath, ui->graphicsView->getVisibleRect(zScale), zScale);
    emit controller->updateMap(dbWithCitiesPath, ui->graphicsView->getVisibleRect(zScale), zScale);
}


void MainWindow::on_connectDB_triggered()
{
    dbConnectorController->showDataBaseConnectionWindow();
}


void MainWindow::on_manageConnections_triggered()
{
    networkController->showConnectionManagmentWindow();
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

