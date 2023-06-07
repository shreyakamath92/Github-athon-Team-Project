#include "AddNote.h"
#include "Note.h"

using namespace std;
#include <time.h>

// default constructor
AddNote::AddNote() { }

// pushing existing notes into vector
void AddNote::addNote(Note note) {
  notes.push_back(note);
}


// printing notes
void AddNote::printNotes() {
  int counter;
  counter = 1;
  // using counter, displaying note and chronological order
  // getting tite, time, and content of each note to display
  for(int i = 0; i < notes.size(); i++) { 
    cout << counter << ") " << convertTimes(notes[i].getTime()) << "\t" << notes[i].getTitle() << "\n\t" << notes[i].getContent() << "\n" << endl;
    counter++;
  }
}


string AddNote::convertTimes(time_t datetime) {
  return ctime(&datetime);
}


// sorting alphabetically
void AddNote::sortByTitle(vector<Note>&notes) {
  // storing size of vector holding notes
  int size = notes.size();
  // sorting alphabetically using bubble sort
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
      if (notes[j].getTitle() > notes[j + 1].getTitle()) {
        swap(notes[j], notes[j + 1]); 
      }
} 

// sorting chronologically
void AddNote::sortByTime(vector<Note>&notes) {
  // storing size of vector holding notes
  int size = notes.size();
  // sorting chronologically using bubble sort
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
      if (notes[j].getTime() > notes[j + 1].getTime()) {
        swap(notes[j], notes[j + 1]); 
      }
}
