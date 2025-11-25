#include "QuizSession.h"
#include <iostream>
#include <ctime>

void QuizSession::run() {
        if (data.getNumQuestions() == 0) {
        cerr << "Khong co cau hoi nao. Vui long kiem tra file input.txt. Ket thuc chuong trinh." << endl;
        return;
    }

    
    view.displayCandidateInfoInput(data.getNumQuestions());
    pair<string, string> info = view.getCandidateInfo();
    candidate.setID(info.first);
    candidate.setName(info.second);

  
    startClock = time(0);
    startTime = *localtime(&startClock);

  
    for (size_t i = 0; i < data.getNumQuestions(); ++i) {
        char currentAnswer = candidate.getAnswer(i);
        // Hiển thị câu hỏi và nhận đáp án/skip
        char response = view.displayQuestion(i, data.getQuestion(i), data.getNumQuestions(), currentAnswer);

        if (response != ' ') {
            candidate.setAnswer(i, response);
        }
    }

  
    while (view.askForAnswerChange(data.getNumQuestions())) {
        int qIndex = view.getQuestionIndexToChange(data.getNumQuestions());
        if (qIndex != -1) {
            char currentAnswer = candidate.getAnswer(qIndex);
            char response = view.displayQuestion(qIndex, data.getQuestion(qIndex), data.getNumQuestions(), currentAnswer);
            
            if (response != ' ') {
                candidate.setAnswer(qIndex, response);
            } else {
                cout << "Input khong hop le. Giu nguyen dap an cu." << endl;
            }
        } else {
            cout << "So cau hoi khong hop le." << endl;
        }
    }

  
    endClock = time(0);
    double elapsedTime = difftime(endClock, startClock); 

    int correctCount = 0;
    for (size_t i = 0; i < data.getNumQuestions(); ++i) {
        char userAnswer = candidate.getAnswer(i);
        // Chỉ tính điểm nếu là đáp án ('a'-'e') và đúng
        if (userAnswer != ' ' && userAnswer != 's' && data.getQuestion(i).checkAnswer(userAnswer)) {
            correctCount++;
        }
    }


    view.displayResult(candidate, startTime, elapsedTime, correctCount, data.getNumQuestions());
}


