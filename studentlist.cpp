#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>

using namespace std;


// credit https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp for iterator


struct Student {
  char fName[15];
  char lName[15];
  int id;
  float gpa;
};

Student* ADD();
void PRINT(vector<Student*> studentList);
void DELETE(vector<Student*> &studentList, int it);

int main()
{

  int quit = 0;
  char input[6];
  vector<Student*> studentList;
  while (quit==0) {
    cout << "Commands are: ADD   PRINT   DELETE   QUIT " << endl;
    cin >> input;
    if (input[0]=='A' && input[1]=='D' && input[2]=='D') {
      cout << "you are creating a new student!" << endl;
      quit=0;
      studentList.push_back(ADD());
    }
    else if (input[0]=='P' && input[1]=='R' && input[2]=='I' && input[3]=='N' && input[4] == 'T' ) {
      cout << "you are printing the student list!" << endl;
      quit=0;
      PRINT(studentList);
    }

    else if (input[0]=='D' && input[1]=='E' && input[2]=='L' && input[3]=='E' && input[4] == 'T' && input[5] == 'E') {
      cout << "You are choosing to delete someone. Please type in their ID: " << endl;
      int idinput;
      cin >> idinput;
      quit=0;
      DELETE(studentList, idinput);
    }

    else if (input[0]=='Q' && input[1]=='U' && input[2]=='I' && input[3]=='T') {
      cout << "Okay, quitting program. Thanks!" << endl;
      quit=1;
    }
    else {
      
      cout << "Not sure what you typed..please try again." << endl;
      quit=0;
    }


  }

  return 0;
}

Student* ADD() {
  Student* newStudent = new Student();
  cout << "you have reached adding a new student" << endl;
  cout << "What is their first name?" << endl;
  cin >> newStudent->fName;
  cout << "What is their last name?" << endl;
  cin >> newStudent->lName;
  //cout << "Their full name is: " << newStudent->fName << " " << newStudent->lName << endl;
  cout << "What is their ID? " << endl;
  cin >> newStudent->id ;
  cout << "What is their GPA? " << endl;
  cin >> newStudent->gpa ;
  //cout << "their id is " << newStudent->id << endl;
  //cout << "their gpa is " << newStudent->gpa << endl;
  return newStudent;

}

void PRINT(vector<Student*> studentList) {

  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2); // making sure that it only prints two values after decimal place
  // setting up iterator to go through the vector
  vector<Student*>::iterator iter = studentList.begin();
  // going through each value in vector and printing vals
  for (iter; iter < studentList.end() ; iter++) {
    cout << "Name: " << (*iter)->fName << " " << (*iter)->lName << "  ID: "  << (*iter)->id << "  GPA: " << (*iter)->gpa << endl;
  }
  return;
}

void DELETE(vector<Student*> &studentList, int id) {
  // setting up iterator to go through vector and check ids
  vector<Student*>::iterator iter = studentList.begin();

  for (iter ; iter <studentList.end() ; iter++) {
    if ((*iter)->id == id) {
      cout << "Deleting student ID: " << id << endl;
      delete *iter;
      studentList.erase(iter);
      return;
    }
    else {
      cout << "Couldn't find anyone with that ID!" << endl;
    }
  }
  // IS NOT FULLY DELETING (WHEN PRINTING THERE IS EXTRA VALS)
  //cout << "Couldn't find anyone with that ID" << endl;
}
