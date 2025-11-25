#pragma once
#include <string>
#include <map>
using namespace std;

class Candidate {
private:
    string id;
    string name;
  
    map<int, char> answers; 

public:

    const string& getID() const;
    const string& getName() const;
    void setID(const string& newID);
    void setName(const string& newName);

    void setAnswer(int qIndex, char answer);
    char getAnswer(int qIndex) const;
};

