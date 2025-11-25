#include "Candidate.h"
#include <algorithm> 

const string& Candidate::getID() const { 
    return id; 
}

const string& Candidate::getName() const { 
    return name; 
}

void Candidate::setID(const string& newID) { 
    id = newID; 
}

void Candidate::setName(const string& newName) { 
    name = newName; 
}


void Candidate::setAnswer(int qIndex, char answer) {
    answers[qIndex] = tolower(answer);
}

char Candidate::getAnswer(int qIndex) const {
    auto it = answers.find(qIndex);
    if (it != answers.end()) {
        return it->second;
    }
    return ' '; 
}