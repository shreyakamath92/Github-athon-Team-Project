#include "Note.h"
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// default constructor
Note::Note() {
  noteTime = 0;
  noteTitle = "";
  noteContent = "";
}

// setting variables to correct values after user input
Note::Note(time_t time, string title, string content) {
  noteTime = time;
  noteTitle = title;
  noteContent = content;
}

// getting time of note creation
time_t Note::getTime() {
  return noteTime;
}

// getting title of note
string Note::getTitle() {
  return noteTitle;
}

// getting content of note
string Note::getContent() {
  return noteContent;
}

// setting title of note to be used in EditNote class
void Note::setTitle(string newTitle) {
  noteTitle = newTitle;
}

// setting content of note to be used in EditNote class
void Note::setContent(string newContent) {
  noteContent = newContent;
}
