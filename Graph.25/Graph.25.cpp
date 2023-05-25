#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Класс для представления графа
class Graph {
public:
    // Конструктор
    Graph(int n) : n(n), dist(n, vector<double>(n)) {}

    // Добавление ребра
    void add_edge(int u, int v, double w) {
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Удаление ребра
    void remove_edge(int u, int v) {
        dist[u][v] = 0;
        dist[v][u] = 0;
    }

    // Добавление вершины
    void add_vertex() {
        n++;
        dist.resize(n, vector<double>(n));
    }

    // Удаление вершины
    void remove_vertex(int v) {
        n--;
        dist.erase(dist.begin() + v);
        for (int i = 0; i < n; i++) {
            dist[i].erase(dist[i].begin() + v);
        }
    }

    // Решение задачи Коммивояжера
    double tsp() {
        // Инициализация переменных
        vector<int> tour(n);
        for (int i = 0; i < n; i++) {
            tour[i] = i;
        }
        double best_dist = numeric_limits<double>::max();

        // Перебор всех возможных маршрутов
        do {
            double dist = 0;
            for (int i = 0; i < n - 1; i++) {
                dist += get_dist(tour[i], tour[i + 1]);
            }
            dist += get_dist(tour[n - 1], tour[0]);
            best_dist = min(best_dist, dist);
        } while (next_permutation(tour.begin() + 1, tour.end()));

        return best_dist;
    }

    // Визуализация графа
    void visualize() {
        cout << "Graph:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int n; // Количество вершин
    vector<vector<double>> dist; // Матрица расстояний

    // Получение расстояния между двумя вершинами
    double get_dist(int u,int v) {
        return dist[u][v];
    }
};

int main() {
    // Создание графа
    Graph g(4);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 15);
    g.add_edge(0, 3, 20);
    g.add_edge(1, 2, 25);
    g.add_edge(1, 3, 30);
    g.add_edge(2, 3, 35);

    // Визуализация графа
    g.visualize();

    // Решение задачи Коммивояжера
    double dist = g.tsp();
    cout << "Shortest tour distance: " << dist << endl;

    // Добавление вершины
    g.add_vertex();
    g.add_edge(3, 4, 5);

    // Удаление вершины
    g.remove_vertex(2);

    // Визуализация графа после изменений
    g.visualize();

    return 0;
}