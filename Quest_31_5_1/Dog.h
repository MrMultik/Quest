#pragma once
#include <memory>
#include <string>
#include "Toy.h"

// Класс собаки
class Dog {
public:
    Dog(const std::string& name) : name_(name) {}

    void getToy(const std::shared_ptr<Toy>& toy) {
        if (!toy) return;

        // Если игрушка уже у этой собаки
        if (toy_ == toy) {
            std::cout << "I already have this toy" << std::endl;
            return;
        }

        // Если игрушка у другой собаки
        if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy" << std::endl;
            return;
        }

        // Игрушка свободна
        toy_ = toy;
    }

    void dropToy() {
        if (!toy_) {
            std::cout << "Nothing to drop" << std::endl;
            return;
        }
        toy_.reset();
    }

private:
    std::string name_;
    std::shared_ptr<Toy> toy_;
};