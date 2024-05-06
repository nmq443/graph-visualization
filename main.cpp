#include "graphvisualization.h"

#include <QApplication>
#include <QPaintEvent>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphVisualization w;
    w.show();

    w.DisplayAdjacentList();

    return a.exec();
}
