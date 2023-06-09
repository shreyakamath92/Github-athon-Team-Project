#include <iostream>
#include <string>
#include <vector>

#ifndef ADDNOTE_H
#define ADDNOTE_H

#include "Note.h"

using namespace std;

class AddNote {

  private:
    

  public:
  // constructor
  AddNote();

  // vector storing user notes
  vector<Note>notes;
  vector<string>titles;

  // functions
  void addNote(Note);
  void printNotes();
  void titlesVector(Note);

  // sorting functions
  void sortByTime(vector<Note>&);
  void sortByTitle(vector<Note>&);

  string convertTimes(time_t);

  // decontructor
  ~AddNote() {};
};
#endif
