#include <iostream>
#include <string>
#include <vector>
#ifndef NOTE_H
#define NOTE_H

using namespace std;

class Note {
  private:
    // private variables
    time_t noteTime;
    string noteTitle;
    string noteContent;


  public:  
    // public methods
    // constructors
    Note();
    Note(time_t, string, string);

    // getter functions
    time_t getTime();
    string getTitle();
    string getContent();

    // setter functions
    void setTitle(string);
    void setContent(string);

    // deconstructor
    ~Note() {};
};

#endif
