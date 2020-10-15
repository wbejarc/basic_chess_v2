#include "chessboard.h"
#include <vector>

ChessBoard::ChessBoard(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{    
}

QRectF ChessBoard::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}

void ChessBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(Qt::black, 2);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(pen);

    // simulamos la creación del tablero con una matriz
    // TODO la matriz debe almacenar objetos tile que almacenen su posición y estado

    std::vector<std::vector<int>> matrix(8, std::vector<int>(8));
    int i = 1;
    int j = 1;
    for(std::vector<int> fila : matrix)
    {
        for(int dummy : fila)
        {
            QPainterPath path;
            path.addRect(400 + (80 * i), 0 + (80 * j), 80, 80);

            if (i%2 == 0 && j%2 != 0)
            {
                painter->fillPath(path, QBrush(QColor(129, 48, 0)));
            }
            else if (j%2 == 0 && i%2 != 0)
            {
                painter->fillPath(path, QBrush(QColor(129, 48, 0)));
            }
            else
            {
                painter->fillPath(path, QBrush(QColor(255, 255, 255)));
            }

            painter->drawPath(path);
            i++;
        }
        i = 1;
        j++;
    }
}
