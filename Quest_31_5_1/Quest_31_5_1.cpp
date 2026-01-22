#include "Dog.h"

int main() {
    auto ball = std::make_shared<Toy>("ball");

    Dog rex("Rex");
    Dog bob("Bob");

    rex.getToy(ball);
    bob.getToy(ball);
    rex.dropToy();
    bob.getToy(ball);

    return 0;
}