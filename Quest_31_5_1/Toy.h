#pragma once
#include <iostream>
#include <string>

// Класс игрушки
class Toy {
public:
    Toy(const std::string& name) : name_(name) {}

    std::string getName() const {
        return name_;
    }

    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped" << std::endl;
    }

private:
    std::string name_;
};