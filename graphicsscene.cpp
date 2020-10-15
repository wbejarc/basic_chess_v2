#include "graphicsscene.h"
#include "globaldefines.h"

GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene(0.0, 0.0, XSIZE, YSIZE, parent)
{
    createObjects();
    configureObjects();
    connectObjects();
}

void GraphicsScene::startScene()
{
    mThreadTimer->start();
}

void GraphicsScene::stopScene()
{
    mThreadTimer->terminate();
}

void GraphicsScene::createObjects()
{
    mThreadTimer = new ThreadTimer(MILISECONDS, this);
    mChessBoard = new ChessBoard();
}

void GraphicsScene::configureObjects()
{
    addItem(mChessBoard);
    addRect(0.0, 0.0, XSIZE, YSIZE, QPen(QColor(Qt::red)));
}

void GraphicsScene::connectObjects()
{
    connect(mThreadTimer, &ThreadTimer::timeOut, this, &GraphicsScene::updateScene);
}

void GraphicsScene::updateScene()
{
    // la lógica del juego
    update();
}
