#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "graphwidget.h"
#include <QInputDialog>
#include <QDebug>
#include <QPainter>
#include <QLabel>


using namespace std;
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    //kommivoyajer
    GraphWidget graphWidget;



    // Create buttons for graph editing
    QPushButton addButton("Добавить вершину");
    QPushButton removeButton("Удалить вершину");
    QPushButton addEdgeButton("добавить ребро");
    QPushButton removeEdgeButton("Удалить ребро");
    QPushButton editMatrixButton("Ред. матрицу");
    QPushButton dfsButton("О.в глубину");
    QPushButton bfsButton("О.в ширину");
    QPushButton dijkstraButton("Алг. Д.");

    // Connect button signals to appropriate slots
    QObject::connect(&addButton, &QPushButton::clicked, [&graphWidget]() {
        // Prompt the user for vertex coordinates
        int x = QInputDialog::getInt(nullptr, "Добавить вершину", "Введите X коорд-ту:");
        int y = QInputDialog::getInt(nullptr, "Добавить вершину", "Введите Y коорд-ту:");

        // Add the vertex to the graph
        graphWidget.addVertex(x, y);
    });

    QObject::connect(&removeButton, &QPushButton::clicked, [&graphWidget]() {
        // Prompt the user for the vertex index to remove
        int index = QInputDialog::getInt(nullptr, "Удалить вершину", "Введите индекс удаляемой вершины:");

        // Remove the vertex from the graph
        graphWidget.removeVertex(index);
    });

    QObject::connect(&addEdgeButton, &QPushButton::clicked, [&graphWidget]() {
        // Prompt the user for the source and destination vertices for the edge
        int from = QInputDialog::getInt(nullptr, "Добавить ребро", "Из вершины:");
        int to = QInputDialog::getInt(nullptr, "Добавить ребро", "В вершину:");

        // Add the edge to the graph
        graphWidget.addEdge(from, to);
    });

    QObject::connect(&removeEdgeButton, &QPushButton::clicked, [&graphWidget]() {
        // Prompt the user for the source and destination vertices of the edge to remove
        int from = QInputDialog::getInt(nullptr, "Удалить ребро", "Из вершины:");
        int to = QInputDialog::getInt(nullptr, "Удалить ребро", "В вершину:");

        // Remove the edge from the graph
        graphWidget.removeEdge(from, to);
    });

    QObject::connect(&editMatrixButton, &QPushButton::clicked, [&graphWidget]() {
        // Prompt the user for the new adjacency matrix
        QVector<QVector<int>> matrix;

        // Assuming a 6x6 matrix for this example
        for (int i = 0; i < 6; ++i) {
            QVector<int> row;
            for (int j = 0; j < 6; ++j) {
                int value = QInputDialog::getInt(nullptr, "Ред. матрицу",
                                                 QString("Введите значение для элемента (%1,%2):").arg(i).arg(j));
                row.append(value);
            }
            matrix.append(row);
        }

        // Set the new adjacency matrix for the graph
        graphWidget.setAdjacencyMatrix(matrix);
    });

    QObject::connect(&dfsButton, &QPushButton::clicked, [&graphWidget]() {
        // Perform depth-first search on the graph
        graphWidget.depthFirstSearch(0); // Start from vertex 0
    });

    QObject::connect(&bfsButton, &QPushButton::clicked, [&graphWidget]() {
        // Perform breadth-first search on the graph
        graphWidget.breadthFirstSearch(0); // Start from vertex 0
    });

    QObject::connect(&dijkstraButton, &QPushButton::clicked, [&graphWidget]() {
        // Perform Dijkstra's algorithm on the graph
        graphWidget.dijkstra(0, 5); // Start from vertex 0
    });

    // Create a layout for the buttons
    QHBoxLayout layout;
    layout.addWidget(&addButton);
    layout.addWidget(&removeButton);
    layout.addWidget(&addEdgeButton);
    layout.addWidget(&removeEdgeButton);
    layout.addWidget(&editMatrixButton);
    layout.addWidget(&dfsButton);
    layout.addWidget(&bfsButton);
    layout.addWidget(&dijkstraButton);

    // Create a main widget and set the layout
    QWidget mainWidget;
    mainWidget.setLayout(&layout);

    // Create a main layout for the main widget
    QVBoxLayout mainLayout;
    mainLayout.addWidget(&graphWidget);
    mainLayout.addWidget(&mainWidget);

    // Set the main layout for the application window
    QWidget window;
    window.setLayout(&mainLayout);
    window.setWindowTitle("Graph Editor");
    window.show();

    return app.exec();
}
