#include <iostream>
#include <string>
#include <vector>

#ifndef EDITNOTE_H
#define EDITNOTE_H

#include "Note.h"
#include "AddNote.h"

class EditNote {
  public: 
  // constructor
  EditNote();

  // editing notes function, 4 parameters
  void editNotes(vector<Note>&, int, int, string);
  
  // deconstructor
  ~EditNote() {};
};

#endif
