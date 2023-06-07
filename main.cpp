// Notesify
// Low Budget Productions - Shreya Kamath, Aleena Abraham, Lilian Nguyen
// 6/6/2023

#include "Note.h"
#include "AddNote.h"
#include "EditNote.h"
#include "DeleteNote.h"
#include "findNote.h"

#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  // declaring variables
  int menuChoice, choice2, choice3, noteCounter, noteNum1, choice4, noteNum2;
  string title, content, content2, title2;
  // variable to determine time
  time_t now;

  // creating objects
  Note note = Note();
  AddNote add = AddNote();
  EditNote edit = EditNote();
  DeleteNote del = DeleteNote();
  findNote find = findNote();

  // counting amount of notes
  noteCounter = 0;

  do {
    // displaying menu options
    cout << "Welcome to Notesify. Choose an option from the menu below to begin: \n\t 1. Add Note\n\t 2. Edit Note\n\t 3. Delete Note\n\t 4. Display Existing Notes\n\t 5. Find a Note \n\t6. Quit \nChoice: "; cin >> menuChoice;

    while(1) {
        if(menuChoice < 1 || menuChoice > 5) {
          cout << "Invalid option. Do you want to: \n\t 1. Add Note\n\t 2. Edit Note\n\t 3. Delete Note\n\t 4. Display Existing Notes\n\t 5. Quit\nChoice: "; cin >> menuChoice;
        }
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Invalid Input. Please enter a NUMBER: \n\t 1. Add Note\n\t 2. Edit Note\n\t 3. Delete Note\n\t 4. Display Existing Notes\n\t 5. Quit\nChoice: "; cin >> menuChoice;
        }
        if((menuChoice >= 1 && menuChoice <= 5) && !cin.fail()) {
          break;
        }
      }

    switch (menuChoice) {
    // adding note case
    case 1: {
      // starting timer
      now = time(0);
      // allowing user to input note title
      cout << "Note Title: "; getline(cin >> ws, title);
      // allowing user to input content
      cout << "Start Typing Here: "; getline(cin >> ws, content); 

      // adding data to notes object, adding note to addNote class object
      note = Note(now, title, content);
      add.addNote(note);
    }
    break;
      
    // editing note case
    case 2: {
      // printing existing notes
      cout << "Existing Notes:\n";
      add.printNotes();
      // allowing user to choose note title/content to edit
      cout << "Which note would you like to edit?: "; cin >> noteNum1;
       //Error Trap
      while(1) {
        if (noteNum1 < 1 || noteNum1 > add.notes.size()) {
          cout << "Invalid note number. Please enter which note would you like to edit?: "; cin >> noteNum1;
        }
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Invalid Input. Please enter a NUMBER. Which note would you like to edit?: "; cin >> noteNum1;
        }
        if ((noteNum1 > 1 && noteNum1 < add.notes.size()) && !cin.fail()) {
          break;
        }
      }
      cout << "Do you want to edit the title (1) or the content (2)?: "; cin >> choice4;
      // error Trap
      while(1) {
        if(choice4 != 1 || choice4 != 2) {
          cout << "Invalid note number. Do you want to edit the title (1) or the content (2)?: "; cin >> choice4;
        }
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Invalid Input. Please enter a NUMBER. Do you want to edit the title (1) or the content (2)?: "; cin >> choice4;
        }
        if((choice4 == 1 || choice4 == 2) && !cin.fail()) {
          break;
        }
      }
      cout << "Start Typing Here: "; getline(cin >> ws, content2); 
      // calling function
      edit.editNotes(add.notes, noteNum1, choice4, content2);
      cout << "Updated Notes:\n";
      // printing updated notes
      add.printNotes();
    }
    break;

    // deleting note case
    case 3: {
      // printing existing notes
      cout << "Existing Notes:\n";
      add.printNotes();
      // user choice of note to delete
      cout << "Which note would you like to delete?: "; cin >> noteNum2;
      //Error Trap
      while(1) {
        if (noteNum2 < 1 || noteNum2 > add.notes.size()) {
          cout << "Invalid note number. Please enter which note would you like to edit?: "; cin >> noteNum2;
        }
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Invalid Input. Please enter a NUMBER. Please enter which note would you like to edit?: "; cin >> noteNum2;
        }
        if ((noteNum2 >= 1 && noteNum2 <= add.notes.size()) && !cin.fail()) {
          break;
        }
      }
      del.deleteNotes(add.notes, noteNum2);
      cout << "Updated Notes:\n";
      add.printNotes();
    }
    break;


      
    // displaying notes
    case 4: {
      // allowing user to choose how notes are displayed in console
      cout << "Display Notes\n\t1) Alphabetically\n\t2) Chronologically?\nChoice: "; cin >> choice2;

      while(1) {
        if(choice2 != 1 || choice2 != 2) {
          cout << "Invalid option. Do you want to display notes Alphabetically (1) or Chronologically(2)? Choice: "; cin >> choice2;
        }
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
          cout << "Invalid Input. Please enter a NUMBER. Do you want to display notes Alphabetically (1) or Chronologically(2)? Choice: "; cin >> choice2;
        }
        if((choice2 == 1 || choice2 == 2) && !cin.fail()) {
          break;
        }
      }
      
       switch(choice2) {
        case 1: {
          cout << "\n";
          // sorting alphabetically bubble sort
          add.sortByTitle(add.notes);
          // printing list with sorted vector
          add.printNotes();
        }
        break;
        
        case 2: {
          cout << "\n";
          // chronologically sorting (notes are in chronological order automatically)
          add.sortByTime(add.notes);
          // printing notes that are stored in vector
          add.printNotes();
        }
        break;
         
        default: {
           cout << "Invalid option.";
         }
         break;

      }
    }
    break;

    case 5: {
      cout << "Enter the title of the note you would like to find: "; cin >> title2;
      find.look(title2);
      find.whenFound(add.notes);
    }
    break;
      
    // quiting
    case 6: {
      cout << "~Thank You For Using Notesify Ltd. 2023!~";
      // exiting program using exit() function
      exit(0);
    }
    break;

    // default for error trapping
    default: {
      cout << "Invalid option. Please try again: ";
    }
    break;
      
  } // End of switch statement
    
  // choice for user to continue choosing from the menu
  cout << "\nEnter any number to choose from the menu again? If not, enter 0 to quit: "; cin >> choice3;
  while(1) {
    if(cin.fail()) {
      cout << "Invalid Input. Please enter a NUMBER: "; cin >> choice3;
    }
    if(!cin.fail())
      break;
  }
    
  }
  while (choice3 != 0);
  cout << "~Thank You For Using Notesify Ltd. 2023!~";
}
