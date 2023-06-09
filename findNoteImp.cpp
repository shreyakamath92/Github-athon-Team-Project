#include "findNote.h"
#include "AddNote.h"
#include "Note.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string.h>

using namespace std;

// constructor
findNote::findNote() { }

//uses linear search to find requested title in all of the note obkects
void findNote::look(vector<Note>notes, string key){
  // linear search
  for (int i = 0; i < notes.size(); i++) {
    if (notes[i].getTitle().compare(key) == 0)
      index = i; 
    else
      index = -1;
  }
}

//coverting time in sec  to readable time
string findNote::convertTimes(time_t time) {
  return ctime(&time);
}

//if element is found, print all corresponding aspects of eleement. if not, return error message
void findNote::whenFound(vector<Note>notes) {
  if(index != -1) {
    cout << "\n" << convertTimes(notes[index].getTime()) << "\t" << notes[index].getTitle() << "\n\t" << notes[index].getContent() << "\n" << endl;
  }
  else {
    cout << "\nYour note was not found in the database.";
  }
}
