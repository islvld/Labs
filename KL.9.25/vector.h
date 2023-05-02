#include <iostream>
#include <cstdlib>
#include "error.h"
class Vector {
private:
    int* data_;
    int size_;

public:
    Vector(int size) : size_(size) {
        data_ = new int[size];
    }

    ~Vector() {};

    int size() const {
        return size_;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw error("Index out of range");
        }
        return data_[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size_) {
            throw error("Index out of range");
        }
        return data_[index];
    }

    int operator*(const Vector& other) const {
        if (size_ != other.size_) {
            throw error("Vectors have different sizes");
        }
        int result = 0;
        for (int i = 0; i < size_; i++) {
            result += data_[i] * other.data_[i];
        }
        return result;
    }

    Vector operator+(int n) const {
        if (n < 0 || n >= size_) {
            throw error("Invalid index for operator +");
        }
        Vector result(size_);
        for (int i = 0; i < size_; i++) {
            result.data_[(i + n) % size_] = data_[i];
        }
        return result;
    }
};
