#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QVector>

struct Vertex {
    int x;
    int y;
};

struct Edge {
    int from;
    int to;
    QGraphicsLineItem* lineItem;
};

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);

    void addVertex(int x, int y);
    void removeVertex(int index);
    void addEdge(int from, int to);
    void removeEdge(int from, int to);
    void setEdgeWeight(int from, int to, int weight);
    void setAdjacencyMatrix(const QVector<QVector<int>> &matrix);

    void breadthFirstSearch(int startVertex);
    void depthFirstSearch(int startVertex);
    void dijkstra(int startVertex, int endVertex);

signals:
    void vertexAdded(int index);
    void vertexRemoved(int index);
    void edgeAdded(int from, int to);
    void edgeRemoved(int from, int to);
    void edgeWeightChanged(int from, int to, int weight);
    void adjacencyMatrixChanged(const QVector<QVector<int>> &matrix);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void wheelEvent(QWheelEvent *event) override;
    void scaleView(qreal scaleFactor);

private:
    QList<Edge> edges;
    QVector<Vertex> vertices;
    QVector<QVector<int>> adjacencyMatrix;
    QVector<QVector<int>> edgeWeights;
    QVector<bool> visited;
    QVector<int> bfsTraversal;
    QVector<int> dfsTraversal;

    void initializeGraph();
    void clearVisited();
    void clearTraversal();
    void dfsRecursive(int vertex);
};

#endif // GRAPHWIDGET_H
