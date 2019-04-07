/*
Josue Guerrero
Arturo Sanchez
4/4/19
Program creates student objects from a file and sorts them by their average,
their first name, calculates a class average, allows a user to search for
a specific student and creates a histogram.

Credits:
Arturo: all Student.h
Josue: all Student.cpp
Both: all project1.cpp
*/

#include "Student.h"
#include <iostream>
using namespace std;

// default constructor
Student::Student(){
  name = "N/A";
  id = 0;
  average = 0;
  grade = 'F';
  rank = 0;
}

// method sets student name
void Student::setName(string name){
  this->name = name;

}

// method sets student id
void Student::setID(int id){
  this->id = id;

}

// method sets student average
void Student::setAverage(int average){
  this->average = average;

  if( average >= 90 )
  {
    setGrade('A');
  }
  else if( 90 > average  && average >= 80 )
  {
    setGrade('B');
  }
  else if( 80 > average  && average >= 70 )
  {
    setGrade('C');
  }
  else if( 70 > average  && average >= 60 )
  {
    setGrade('D');
  }
  else if( 60 > average )
  {
    setGrade('F');
  }
}

// method sets student grade
void Student::setGrade(char grade){
  this->grade = grade;

}

// method sets student rank
void Student::setRank(int rank){
  this->rank = rank;

}

// method gets student name
string Student::getName() const{
  return name;

}

// method gets student id
int Student::getID() const{
  return id;

}

// method gets student average
double Student::getAverage() const{
  return average;

}

// method gets student grade
char Student::getGrade() const{
  return grade;

}

// method gets student rank
int Student::getRank() const{
  return rank;

}

// method prints sudent info
void Student::print() const{
  cout << name << " " << id << " - " << average << "  (" << grade << ")  (rank: " << rank << ")" << endl;
}
