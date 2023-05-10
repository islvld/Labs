#pragma once
#include <iostream>
#include <cstdlib>
class error {
private:
    std::string message_;

public:
    error(const std::string& message) : message_(message) {}

    const std::string& message() const {
        return message_;
    }
};