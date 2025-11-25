#include "Question.h"
#include <algorithm> 


Question::Question() : correctAnswer(' ') {}

Question::Question(const string& text, const vector<string>& opts, char correct)
    : questionText(text), options(opts), correctAnswer(correct) {}

const string& Question::getText() const { 
    return questionText; 
}

const vector<string>& Question::getOptions() const { 
    return options; 
}

char Question::getCorrectAnswer() const { 
    return correctAnswer; 
}

bool Question::checkAnswer(char userResponse) const {

    return tolower(userResponse) == tolower(correctAnswer);
}