#include <iostream>

template <typename T>
class Vector {
private:
    T* data; // указатель на массив, хранящий элементы вектора
    int size; // размер вектора
public:
    Vector() : data(nullptr), size(0) {} // конструктор по умолчанию
    Vector(int size, T value = T()) : size(size) { // конструктор, принимающий размер вектора и начальное значение элементов
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }
    ~Vector() { // деструктор
        delete[] data;
    }
    Vector(const Vector& other) : size(other.size) { // конструктор копирования
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    Vector& operator=(const Vector& other) { // оператор присваивания
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    T& operator[](int index) { // перегруженный оператор доступа по индексу
        return data[index];
    }
    int get_size() const { // метод, возвращающий размер вектора
        return size;
    }
    Vector operator*(const Vector& other) const { // перегруженный оператор умножения векторов
        int n = std::min(size, other.size); // определяем количество элементов для умножения
        Vector result(n);
        for (int i = 0; i < n; i++) {
            result.data[i] = data[i] * other.data[i];
        }
        return result;
    }
};
