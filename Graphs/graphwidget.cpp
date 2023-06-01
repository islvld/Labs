#include "graphwidget.h"
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QPainter>
#include <QDebug>
#include <climits>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing, true);
    setRenderHint(QPainter::TextAntialiasing, true);

    initializeGraph();
}

void GraphWidget::addVertex(int x, int y) {
    Vertex vertex;
    vertex.x = x;
    vertex.y = y;
    vertices.append(vertex);
    adjacencyMatrix.resize(vertices.size());
    edgeWeights.resize(vertices.size());
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        adjacencyMatrix[i].resize(vertices.size());
        edgeWeights[i].resize(vertices.size());
    }

    // Update scene
    QGraphicsEllipseItem *ellipseItem = scene()->addEllipse(x - 20, y - 20, 40, 40);
    QGraphicsTextItem *textItem = scene()->addText(QString::number(vertices.size() - 1), QFont("Arial", 12));
    textItem->setPos(x - 6, y - 12);

    emit vertexAdded(vertices.size() - 1);
}

void GraphWidget::removeVertex(int index) {
    if (index < 0 || index >= vertices.size())
        return;

    vertices.remove(index);
    adjacencyMatrix.remove(index);
    edgeWeights.remove(index);
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        adjacencyMatrix[i].remove(index);
        edgeWeights[i].remove(index);
    }

    // Update scene
    scene()->clear();
    for (int i = 0; i < vertices.size(); ++i) {
        QGraphicsEllipseItem *ellipseItem = scene()->addEllipse(vertices[i].x - 20, vertices[i].y - 20, 40, 40);
        QGraphicsTextItem *textItem = scene()->addText(QString::number(i), QFont("Arial", 12));
        textItem->setPos(vertices[i].x - 6, vertices[i].y - 12);
    }

    emit vertexRemoved(index);
}

void GraphWidget::addEdge(int from, int to) {
    if (from < 0 || from >= vertices.size() || to < 0 || to >= vertices.size())
        return;

    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;

    // Update scene
    QGraphicsLineItem *lineItem = scene()->addLine(vertices[from].x, vertices[from].y, vertices[to].x, vertices[to].y);
    lineItem->setFlag(QGraphicsItem::ItemIsSelectable, true);

    emit edgeAdded(from, to);
}

void GraphWidget::removeEdge(int from, int to) {
    if (from < 0 || from >= vertices.size() || to < 0 || to >= vertices.size())
        return;

    adjacencyMatrix[from][to] = 0;
    adjacencyMatrix[to][from] = 0;

    // Update scene
    QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        QGraphicsLineItem *lineItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        if (lineItem && lineItem->line().p1().x() == vertices[from].x && lineItem->line().p1().y() == vertices[from].y &&
            lineItem->line().p2().x() == vertices[to].x && lineItem->line().p2().y() == vertices[to].y) {
            scene()->removeItem(lineItem);
            delete lineItem;
            break;
        }
    }

    emit edgeRemoved(from, to);
}

void GraphWidget::setEdgeWeight(int from, int to, int weight) {
    if (from < 0 || from >= vertices.size() || to < 0 || to >= vertices.size())
        return;

    edgeWeights[from][to] = weight;
    edgeWeights[to][from] = weight;

    emit edgeWeightChanged(from, to, weight);
}

void GraphWidget::setAdjacencyMatrix(const QVector<QVector<int>> &matrix) {
    if (matrix.size() != vertices.size())
        return;

    adjacencyMatrix = matrix;

    // Update scene
    scene()->clear();
    for (int i = 0; i < vertices.size(); ++i) {
        QGraphicsEllipseItem *ellipseItem = scene()->addEllipse(vertices[i].x - 20, vertices[i].y - 20, 40, 40);
        QGraphicsTextItem *textItem = scene()->addText(QString::number(i), QFont("Arial", 12));
        textItem->setPos(vertices[i].x - 6, vertices[i].y - 12);
    }
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = i + 1; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                QGraphicsLineItem *lineItem = scene()->addLine(vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y);
                lineItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
            }
        }
    }

    emit adjacencyMatrixChanged(adjacencyMatrix);
}

void GraphWidget::breadthFirstSearch(int startVertex) {
    clearVisited();
    clearTraversal();

    QList<int> queue;
    visited[startVertex] = true;
    queue.append(startVertex);
    bfsTraversal.append(startVertex);

    while (!queue.isEmpty()) {
        int currentVertex = queue.takeFirst();
        for (int i = 0; i < adjacencyMatrix[currentVertex].size(); ++i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.append(i);
                bfsTraversal.append(i);
            }
        }
    }

    qDebug() << "Обход в ширину:" << bfsTraversal;
}

void GraphWidget::depthFirstSearch(int startVertex) {
    clearVisited();
    clearTraversal();

    dfsRecursive(startVertex);

    qDebug() << "Обход в глубину:" << dfsTraversal;
}

void GraphWidget::dijkstra(int startVertex, int endVertex) {
    if (startVertex < 0 || startVertex >= vertices.size() || endVertex < 0 || endVertex >= vertices.size())
        return;

    QVector<int> distance(vertices.size(), INT_MAX);
    QVector<bool> visited(vertices.size(), false);
    QVector<int> previous(vertices.size(), -1);

    distance[startVertex] = 0;

    for (int i = 0; i < vertices.size() - 1; ++i) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < vertices.size(); ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        for (int j = 0; j < vertices.size(); ++j) {
            if (!visited[j] && adjacencyMatrix[minIndex][j] == 1 && distance[minIndex] != INT_MAX &&
                distance[minIndex] + edgeWeights[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + edgeWeights[minIndex][j];
                previous[j] = minIndex;
            }
        }
    }

    QVector<int> shortestPath;
    int currentVertex = endVertex;
    while (currentVertex != -1) {
        shortestPath.prepend(currentVertex);
        currentVertex = previous[currentVertex];
    }

    qDebug() << "Кратчайший путь" << startVertex << "в" << endVertex << ":" << shortestPath;
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRect(-2000, -2000, 4000, 4000);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 0.5));

    for (int i = 0; i < vertices.size(); ++i) {
        for (int j = i + 1; j < vertices.size(); ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                painter->drawLine(vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y);
            }
        }
    }
}

void GraphWidget::wheelEvent(QWheelEvent *event) {
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void GraphWidget::scaleView(qreal scaleFactor) {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void GraphWidget::initializeGraph() {
    vertices.clear();
    adjacencyMatrix.clear();
    edgeWeights.clear();
    visited.clear();
    bfsTraversal.clear();
    dfsTraversal.clear();

    clearTraversal();

    scene()->clear();
}

void GraphWidget::clearVisited() {
    visited.clear();
    visited.resize(vertices.size());
}

void GraphWidget::clearTraversal() {
    bfsTraversal.clear();
    dfsTraversal.clear();
}

void GraphWidget::dfsRecursive(int vertex) {
    visited[vertex] = true;
    dfsTraversal.append(vertex);

    for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            dfsRecursive(i);
        }
    }
}
