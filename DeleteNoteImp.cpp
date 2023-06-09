#include "Note.h"
#include "AddNote.h"
#include "EditNote.h"
#include "DeleteNote.h"

#include <vector>
#include <limits>
using namespace std;

// constructor
DeleteNote::DeleteNote() { };
// deleting note function, two parameters
// passing notes vectors by reference to change size
void DeleteNote::deleteNotes(vector<Note>&notes, int noteNum) {
  // storing position of note
  int realPos = noteNum - 1;
  // using erase() function to delete note
  notes.erase(notes.begin()+realPos);
}
