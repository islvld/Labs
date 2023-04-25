#include <iostream>

struct Node {
    int key;
    Node* next;
    Node(int key) : key(key), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {}

    // Добавление элемента в конец списка
    void add(int key) {
        Node* newNode = new Node(key);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    // Удаление элементов из списка, начиная с заданного номера
    void remove(int start, int count) {
        if (start >= size || count == 0) {
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < start; i++) {
            prev = curr;
            curr = curr->next;
        }
        for (int i = 0; i < count && curr != nullptr; i++) {
            Node* next = curr->next;
            delete curr;
            curr = next;
            size--;
        }
        if (prev == nullptr) {
            head = curr;
        }
        else {
            prev->next = curr;
        }
    }

    // Добавление элементов в список, начиная с заданного номера
    void insert(int start, int count) {
        if (start > size) {
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < start; i++) {
            prev = curr;
            curr = curr->next;
        }
        for (int i = 0; i < count; i++) {
            Node* newNode = new Node(rand() % 100);
            newNode->next = curr;
            if (prev == nullptr) {
                head = newNode;
            }
            else {
                prev->next = newNode;
            }
            prev = newNode;
            size++;
        }
    }

    // Вывод элементов списка на экран
    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->key << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;
    int size;
};

int main() {
    LinkedList list;
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }
    list.print(); // 0 1 2 3 4 5 6 7 8 9
    list.remove(3, 4);
    list.print(); // 0 1 2 7 8 9
    list.insert(3, 2);
    list.print(); // 0 1 2 78 52 7 8 9
    return 0;
}
