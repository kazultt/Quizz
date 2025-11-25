#pragma once
#include "QuizData.h"
#include "Candidate.h"
#include "QuizView.h"
#include <ctime>

class QuizSession {
private:
    QuizData data;
    Candidate candidate;
    QuizView view;
    tm startTime;
    time_t startClock;
    time_t endClock;

public:
    void run();
};
