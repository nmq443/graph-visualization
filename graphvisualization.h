#ifndef GRAPHVISUALIZATION_H
#define GRAPHVISUALIZATION_H

#include <QMainWindow>
#include <QPainter>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphVisualization;
}
QT_END_NAMESPACE

class GraphVisualization : public QMainWindow
{
    Q_OBJECT

public:
    GraphVisualization(QWidget *parent = nullptr);
    GraphVisualization(int num_vertices, QWidget *parent = nullptr);
    ~GraphVisualization();

    virtual void paintEvent(QPaintEvent *event);

    void DisplayAdjacentList();


private:
    Ui::GraphVisualization *ui;
    UndirectedGraph udir_graph;
};
#endif // GRAPHVISUALIZATION_H
