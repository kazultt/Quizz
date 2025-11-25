#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> options; 
    char correctAnswer;      

public:

    Question();
    Question(const string& text, const vector<string>& opts, char correct);
    const string& getText() const;
    const vector<string>& getOptions() const;
    char getCorrectAnswer() const;
    bool checkAnswer(char userResponse) const;
};



