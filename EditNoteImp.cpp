#include "Note.h"
#include "AddNote.h"
#include "EditNote.h"

using namespace std;

// constructor
EditNote::EditNote() { }

void EditNote::editNotes(vector<Note>&notes, int noteNum, int choice, string newStuff) {
  if(choice == 1) {
    // changing title depending on user choice  
    // setTitle() function from notes class
    notes[noteNum - 1].setTitle(newStuff);
  } else if(choice == 2) {
    // changing content depending on user choice  
    // setContent() function from notes class
    notes[noteNum - 1].setContent(newStuff);
  } else {
    cout << "Invalid option. Please choose again: "; cin >> choice;
  }
}
