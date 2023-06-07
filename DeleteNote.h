#include <iostream>
#include <string>
#include <vector>

#ifndef DELETENOTE_H
#define DELETENOTE_H

#include "Note.h"
#include "AddNote.h"
#include "EditNote.h"

class DeleteNote {
  private:

  public:
  // constructor
  DeleteNote();
  // deleting function
  void deleteNotes(vector<Note>&, int);

  // ~DeleteNote();

};
#endif
