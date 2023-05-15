#include <iostream>
#include <map>
#include <algorithm>

template <typename T, typename Container = std::map<int, T>>
class Vector {
private:
    Container data_;

public:
    void addElement(int pos, const T& element) {
        data_[pos] = element;
    }

    void removeElement(int pos) {
        auto it = data_.find(pos);
        if (it != data_.end()) {
            data_.erase(it);
        }
    }

    T getMinimumElement() const {
        auto it = std::min_element(data_.begin(), data_.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

        if (it != data_.end()) {
            return it->second;
        }

        // Return a default-constructed value if the container is empty
        return T();
    }

    double getArithmeticMean() const {
        double sum = 0.0;
        for (const auto& pair : data_) {
            sum += pair.second;
        }

        return sum / data_.size();
    }

    void addMinimumToPosition(int pos) {
        T minElement = getMinimumElement();
        data_[pos] = minElement;
    }

    void removeLargerThanMean() {
        double mean = getArithmeticMean();
        auto it = data_.begin();
        while (it != data_.end()) {
            if (it->second > mean) {
                it = data_.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void multiplyByMaximum() {
        auto maxIt = std::max_element(data_.begin(), data_.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

        if (maxIt != data_.end()) {
            T maxElement = maxIt->second;
            for (auto& pair : data_) {
                pair.second *= maxElement;
            }
        }
    }

    void print() const {
        for (const auto& pair : data_) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main() {
    Vector<int> vec;

    vec.addElement(0, 5);
    vec.addElement(1, 2);
    vec.addElement(2, 7);
    vec.addElement(3, 3);
    vec.addElement(4, 1);

    std::cout << "Initial vector:" << std::endl;
    vec.print();

    int minimum = vec.getMinimumElement();
    std::cout << "Minimum element: " << minimum << std::endl;

    vec.addMinimumToPosition(5);
    std::cout << "Vector after adding minimum to position 5:" << std::endl;
    vec.print();

    vec.removeLargerThanMean();
    std::cout << "Vector after removing elements larger than the mean:" << std::endl;
    vec.print();

    vec.multiplyByMaximum();
    std::cout << "Vector after multiplying each element by the maximum:" << std::endl;
    vec.print();

    return 0;
}
