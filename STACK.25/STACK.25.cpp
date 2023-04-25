#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    T peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    std::cout << stack.isEmpty() << std::endl;
    return 0;
}

//В данной реализации стека с помощью односвязного списка создается класс Stack, содержащий приватное поле top, указывающее на вершину стека.
//Внутренний класс Node используется для хранения данных элемента стека и указателя на следующий элемент.
//Метод push добавляет новый элемент на вершину стека.
//Метод pop удаляет элемент с вершины стека и возвращает его значение.Метод peek возвращает значение элемента на вершине стека, не удаляя его.
//Метод isEmpty проверяет, пуст ли стек.