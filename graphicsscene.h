#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

#include "chessboard.h"
#include "threadtimer.h"

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(QObject *parent = nullptr);
    void startScene();
    void stopScene();

private:
    void createObjects();
    void configureObjects();
    void connectObjects();
    void updateScene();

    ChessBoard *mChessBoard;
    ThreadTimer *mThreadTimer;
};

#endif // GRAPHICSSCENE_H
