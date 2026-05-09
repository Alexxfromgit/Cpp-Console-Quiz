#pragma once
#include <string>
#include <vector>

struct Question {
    std::string text;
    std::vector<std::string> options;
    std::vector<int> scores; // per-option score delta
};

class Quiz {
public:
    explicit Quiz(std::string playerName);
    void run();

private:
    std::string playerName_;
    int score_ = 0;
    std::vector<Question> questions_;

    void loadQuestions();
    int askQuestion(const Question& q) const;
    void printResult() const;
};
