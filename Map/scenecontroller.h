#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QRectF>
#include <QString>

class SceneController : public QGraphicsScene
{
    Q_OBJECT

public:
    SceneController(QObject *parent);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:

public slots:

signals:
    void mousePositionChanged(QPointF position);
};

#endif // SCENECONTROLLER_H
