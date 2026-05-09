#include <iostream>
#include <string>
#include "quiz.h"

int main() {
    std::cout << "Welcome to the C++ Quiz!\n";
    std::cout << "Use keyboard numbers to answer.\n";
    std::cout << "Best of luck!\n\n";

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "\nHi " << name << ". Let's begin...\n";

    Quiz quiz(name);
    quiz.run();

    return 0;
}
