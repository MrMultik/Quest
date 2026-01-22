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

// Аналог shared_ptr для Toy
class shared_ptr_toy {
public:
    shared_ptr_toy() : toy_(nullptr), count_(nullptr) {}

    explicit shared_ptr_toy(const std::string& name) {
        toy_ = new Toy(name);
        count_ = new int(1);
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        toy_ = other.toy_;
        count_ = other.count_;
        if (count_) ++(*count_);
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this == &other || toy_ == other.toy_)
            return *this;

        release();
        toy_ = other.toy_;
        count_ = other.count_;
        if (count_) ++(*count_);
        return *this;
    }

    ~shared_ptr_toy() {
        release();
    }

    void reset() {
        release();
        toy_ = nullptr;
        count_ = nullptr;
    }

    Toy* get() const {
        return toy_;
    }

    int use_count() const {
        return count_ ? *count_ : 0;
    }

    std::string getToyName() const {
        return toy_ ? toy_->getName() : "Nothing";
    }

private:
    Toy* toy_;
    int* count_;

    void release() {
        if (count_) {
            --(*count_);
            if (*count_ == 0) {
                delete toy_;
                delete count_;
            }
        }
    }
};

// Фабричная функция
shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(name);
}