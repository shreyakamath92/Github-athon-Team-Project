#include "findNote.h"
#include "AddNote.h"
#include "Note.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// constructor
findNote::findNote() { }

//Make a string capital
void findNote::toUppercase(string& title) {
  char s;
  string str, strTochr;
  str = "";
  
  for(int i = 0; i < title.size(); i++) {
    // shift all characters to uppercase
    s = toupper(title[i]);
    str += s;
  }
  title = str;
} 

// create titles vector
void findNote::titlesVector(vector<Note>notes) {
  string str;

  for(int i = 0; i < notes.size(); i++) {
    str = notes[i].getTitle(); //Takes title
    toUppercase(str);
    titles[i] = str;
  }
}

void findNote::look(string key){
  // shift key to uppercase
  toUppercase(key);
  
  // linear search
  for (int i = 0; i < titles.size(); i++) {
    if (titles[i] == key)
      index = i; 
    else
      index = -1;
  }
}

string findNote::convertTimes(time_t time) {
  return ctime(&time);
}


void findNote::whenFound(vector<Note>notes) {
  if(index != -1) {
    cout << convertTimes(notes[index].getTime()) << "\t" << notes[index].getTitle() << "\n\t" << notes[index].getContent() << "\n" << endl;
  }
  else {
    cout << "Your note was not found in the database.";
  }
}
