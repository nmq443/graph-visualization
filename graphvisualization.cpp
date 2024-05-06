#include "graphvisualization.h"
#include "./ui_graphvisualization.h"

GraphVisualization::GraphVisualization(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphVisualization)
{
    ui->setupUi(this);
    udir_graph = UndirectedGraph();
    udir_graph.CreateRandomGraph(10, 20);
}

GraphVisualization::GraphVisualization(int num_vertices, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphVisualization)
{
    ui->setupUi(this);
    udir_graph = UndirectedGraph(num_vertices);
}

GraphVisualization::~GraphVisualization()
{
    delete ui;
}

void GraphVisualization::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(0, 0, 200, 200);
}

void GraphVisualization::DisplayAdjacentList()
{
    udir_graph.DisplayGraph();
}
