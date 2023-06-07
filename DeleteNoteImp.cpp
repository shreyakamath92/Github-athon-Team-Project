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
  /*
  while (true) {
    //Error Trapping
    //User Input
    if (cin >> noteNum) {
      break;
    }
    //If user does not input integer error pops up
    else {
      cout << "Invalid input. Please enter a valid integer: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //If user does not enter an existing note number it will give an error
  }
  if (noteNum <= 0 || noteNum > notes.size()) {
    cout << "Invalid note number\n";
    return;
  }
*/
  // storing position of note
  int realPos = noteNum - 1;
  // using erase() function to delete note
  notes.erase(notes.begin()+realPos);
}
