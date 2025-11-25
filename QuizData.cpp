#include "QuizData.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

QuizData::QuizData() {
    loadQuestions();
}

bool QuizData::loadQuestions() {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    questions.clear();
    string line;
    
    while (getline(file, line)) {
        string questionText = line; 

        if (!getline(file, line)) break; 
        stringstream ss(line);
        string option;
        vector<string> options;
        while (ss >> option) {
            options.push_back(option);
        }
        
        char correctAnswer = ' ';
        if (!getline(file, line)) break;
        if (!line.empty()) {
            correctAnswer = tolower(line[0]);
        }
        
        if (options.empty()) { 
            cout << "Loi dinh dang file input.txt: Thieu lua chon cho cau hoi." << endl;
            continue; 
        }

        questions.emplace_back(questionText, options, correctAnswer);
    }
    file.close();
    return true;
}

size_t QuizData::getNumQuestions() const { 
    return questions.size(); 
}

const Question& QuizData::getQuestion(size_t index) const { 
    return questions[index]; 
}