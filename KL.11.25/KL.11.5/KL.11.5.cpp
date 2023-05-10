#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T, template <typename, typename> class Container>
class Vector {
public:
    Vector() {}
    void add(T element) {
        container.push(element);
    }
    void remove() {
        container.pop();
    }
    // В методе multiply_by_max мы используем функцию std::max_element, чтобы найти максимальный элемент контейнера, а затем умножаем каждый элемент на этот максимум.
    void multiply_by_max() {
        T max_element = *std::max_element(std::begin(container), std::end(container));
        for (auto& element : container) {
            element *= max_element;
        }
    }
    void print() {
        while (!container.empty()) {
            std::cout << container.top() << " ";
            container.pop();
        }
        std::cout << std::endl;
    }
private:
    Container<T, std::deque<T>> container;
};

int main() {
    Vector<int, std::stack> v;
    v.add(5);
    v.add(10);
    v.add(15);
    v.multiply_by_max();
    v.print();
    return 0;
}
