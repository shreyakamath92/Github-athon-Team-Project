#include <iostream>
#include <string>
#include <vector>

#ifndef FINDNOTE_H
#define FINDNOTE_H

// including files
#include "Note.h"
#include "AddNote.h"

class findNote {
private:
// private vector to hold titles
  vector<string>titles;
  int index;

public:
// constructor
findNote();

// public functions
void toUppercase(string&);
void titlesVector(vector<Note>);
void look(string);
void whenFound(vector<Note>);
string convertTimes(time_t);

// deconstructor
~findNote() {};
};

#endif
