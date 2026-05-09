#include "quiz.h"
#include <iostream>
#include <limits>

Quiz::Quiz(std::string playerName) : playerName_(std::move(playerName)) {
    loadQuestions();
}

void Quiz::loadQuestions() {
    questions_ = {
        {
            "1. C++ is a:",
            {"General purpose programming language", "Client-side scripting language", "Movie making program"},
            {1, 0, -1}
        },
        {
            "2. What is the starting point for a computer program?",
            {"First line", "Main function", "From <iostream>"},
            {-1, 1, 0}
        },
        {
            "3. Which of the following is a C++ compiler?",
            {"Console", "GAC", "CodeBlocks", "GNU GCC"},
            {-1, 0, -1, 1}
        },
        {
            "4. What should be used to move to a new line?",
            {"#include", "endl", "startl", "return"},
            {0, 1, -1, 0}
        },
        {
            "5. Which of the following is true about comments?",
            {"Comments are used to confuse programmers",
             "Single line comment starts with an * (asterisk)",
             "Comments are ignored by the compiler"},
            {-1, 0, 1}
        },
        {
            "6. How many times should a data type be mentioned for a variable?",
            {"Everywhere the variable is used",
             "When printing a variable's value",
             "Only once: when declaring the variable",
             "When entering variable's value using cin"},
            {-1, 0, 1, -1}
        },
        {
            "7. x++ has the same meaning as:",
            {"x = x - 4;", "x /= 17;", "x = x + 1;", "x = x + x"},
            {-1, -1, 1, 0}
        },
        {
            "8. Which shows the correct syntax for the if statement in C++?",
            {"IF test", "if (test) { }", "if test", "if test { }"},
            {-1, 1, -1, 0}
        },
        {
            "9. Which is the right syntax for the while loop?",
            {"WHILE bacon <= 5 { cout << text; }",
             "while bacon <= 5 cout << text;",
             "while (bacon <= 5) { cout << text; }"},
            {-1, 0, 1}
        },
        {
            "10. How is a do...while loop different from a while loop?",
            {"do...while loop tests the condition before running the code",
             "while loop runs the code before testing the condition",
             "do...while loop runs your code at least one time"},
            {-1, 0, 1}
        },
        {
            "11. Which statement about switch is true?",
            {"The switch statement may be an alternative for multiple if statements",
             "The switch statement must always contain a default case",
             "The switch statement is the same as the for loop"},
            {1, -1, 0}
        },
        {
            "12. The result of 'a && b' is true if:",
            {"Both a and b are false", "Both a and b are true", "Either a or b is true"},
            {-1, 1, 0}
        }
    };
}

int Quiz::askQuestion(const Question& q) const {
    std::cout << "\n" << q.text << "\n\n";
    for (int i = 0; i < static_cast<int>(q.options.size()); ++i) {
        std::cout << "  " << (i + 1) << ". " << q.options[i] << "\n";
    }

    int answer;
    while (true) {
        std::cout << "\nYour answer: ";
        if (std::cin >> answer && answer >= 1 && answer <= static_cast<int>(q.options.size())) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Be careful. Wrong number for answer!\n";
    }
    return answer;
}

void Quiz::run() {
    for (const auto& q : questions_) {
        int answer = askQuestion(q);
        score_ += q.scores[answer - 1];
    }
    printResult();
}

void Quiz::printResult() const {
    int total = static_cast<int>(questions_.size());
    std::cout << "\nYour result: " << score_ << " of " << total << "\n\n";

    if (score_ >= 1 && score_ <= 4) {
        std::cout << "You don't pass the test.\n";
    } else if (score_ >= 5 && score_ <= 7) {
        std::cout << "Bad results. You need more learning.\n";
    } else if (score_ >= 8 && score_ <= 10) {
        std::cout << "Good. You have passed the test.\n";
    } else if (score_ == 11) {
        std::cout << "Excellent! " << playerName_ << ". You have passed the test!\n";
    } else if (score_ == 12) {
        std::cout << "Congratulations!!! " << playerName_ << ". Great result! You are a guru of C++ :)\n";
    } else {
        std::cout << "Do you pass the test in less than 30 seconds? :)\n";
    }
}
