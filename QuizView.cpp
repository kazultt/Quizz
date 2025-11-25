#include "QuizView.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm> 

void QuizView::printHeader(const string& title, size_t numQuestions) const {
    cout << "\n*****************************" << endl;
    cout << "* " << setw(25) << left << title << "*" << endl;
    cout << "* Date:25/11/2025         *" << endl;
    cout << "* Number of questions: " << setw(4) << left << numQuestions << "*" << endl;
    cout << "*****************************" << endl;
}


string QuizView::answerToString(char answer) const {
    if (answer == 'S') return "**SKIP**";
    if (answer == ' ') return "**Chua tra loi**";
    return string(1, toupper(answer));
}


void QuizView::displayCandidateInfoInput(size_t numQuestions) const {
    printHeader("Quiz Program", numQuestions);
    cout << "Please enter your information!" << endl;
}

pair<string, string> QuizView::getCandidateInfo() const {
    string id, name;
    cout << "Your id: ";

    getline(cin, id); 
    cout << "Your name: ";
    getline(cin, name);
    return {id, name};
}

char QuizView::displayQuestion(int index, const Question& q, size_t numQuestions, char currentAnswer) const {

    printHeader("Quiz Program", numQuestions);
    cout << "Q" << index + 1 << ". " << q.getText() << endl;

    char optionChar = 'a';
    const auto& options = q.getOptions();
    for (size_t i = 0; i < options.size(); ++i) {
        cout << optionChar << ". " << options[i] << endl;
        optionChar++;
    }

    if (currentAnswer != ' ' && currentAnswer != 'S') {
        cout << "Your current answer: " << answerToString(currentAnswer) << endl;
    } else if (currentAnswer == 'S') {
        cout << "Your current status: **SKIP**" << endl;
    }
    
    char response_step1 = ' ';
    string input_step1;
    
 
    cout << "Answer(A) or Skip(S)?"; 
    
    getline(cin, input_step1);
    if (!input_step1.empty()) {
        response_step1 = tolower(input_step1[0]);
    } else {
        return ' '; 
    }

    if (response_step1 == 's') {
        return 's'; 
    }
    

    string input_step2;
    cout << "Your answer:"; 
    getline(cin, input_step2);

    if (input_step2.empty()) return ' '; 

    char response_final = tolower(input_step2[0]);
    size_t numOptions = options.size();
    
    if (response_final >= 'a' && response_final < (char)('a' + numOptions)) {
        return response_final;
    }
    
    return ' '; 
}

bool QuizView::askForAnswerChange(size_t numQuestions) const {
    printHeader("Quiz Program", numQuestions);
    cout << "Do you want to change any answers? (Y/N)" << endl;
    string input;
    getline(cin, input);
    if (input.empty()) return false;
    return tolower(input[0]) == 'y';
}

int QuizView::getQuestionIndexToChange(size_t numQuestions) const {
    cout << "Enter the question number (1-" << numQuestions << ") to change: ";
    string input;
    getline(cin, input);
    try {
        int index = stoi(input);
        if (index >= 1 && index <= (int)numQuestions) {
            return index - 1; 
        }
    } catch (...) {}
    return -1; 
}

void QuizView::displayResult(const Candidate& candidate, const tm& startTime, double elapsedTime, int correctCount, size_t totalQuestions) const {
    cout << "\nResult of quiz:" << endl;
    cout << "----------------------------------" << endl;
    cout << "ID: " << candidate.getID() << endl;
    cout << "Name: " << candidate.getName() << endl;
    
    char timeBuffer[80];
    strftime(timeBuffer, sizeof(timeBuffer), "%d/%m/%Y at %H:%M:%S", &startTime);
    cout << "Quiz started on " << timeBuffer << endl;
    
    cout << "Elapsed time: " << fixed << setprecision(0) << elapsedTime << " seconds." << endl;
    
    cout << "Correct answers: " << correctCount << "/" << totalQuestions << endl;
    
    cout << "Total point of quiz: " << correctCount*2 << endl; 

    cout << "\nPress any key to continue . . . ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}