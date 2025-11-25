#pragma once
#include "Question.h"
#include "Candidate.h"
#include <ctime>
#include <string>

using namespace std;

class QuizView {
private:
    void printHeader(const string& title, size_t numQuestions) const;
    string answerToString(char answer) const;

public:

    void displayCandidateInfoInput(size_t numQuestions) const;
    pair<string, string> getCandidateInfo() const;
    int getQuestionIndexToChange(size_t numQuestions) const;

    char displayQuestion(int index, const Question& q, size_t numQuestions, char currentAnswer) const;
    bool askForAnswerChange(size_t numQuestions) const;
    void displayResult(const Candidate& candidate, const tm& startTime, double elapsedTime, int correctCount, size_t totalQuestions) const;
};

