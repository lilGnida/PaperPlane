#include "Map/scenecontroller.h"
#include <QDebug>

SceneController::SceneController(QObject *parent) : QGraphicsScene(parent)
{

}

void SceneController::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mousePositionChanged(event->scenePos());
}
