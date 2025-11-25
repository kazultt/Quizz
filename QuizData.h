#pragma once
#include "Question.h"
#include <vector>
#include <string>
using namespace std;

class QuizData {
private:
    vector<Question> questions;
    const string filename = "input.txt"; 

public:
    QuizData();
    bool loadQuestions();

    size_t getNumQuestions() const;
    const Question& getQuestion(size_t index) const;
};

