#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(){


}

void Student::setName(string name){
  this->name = name;

}

void Student::setID(int id){
  this->id = id;

}

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

void Student::setGrade(char grade){
  this->grade = grade;

}

void Student::setRank(int rank){
  this->rank = rank;

}

string Student::getName() const{
  return name;

}

int Student::getID() const{
  return id;

}
double Student::getAverage() const{
  return average;

}
char Student::getGrade() const{
  return grade;

}

int Student::getRank() const{
  return rank;

}

void Student::print() const{
  cout << name << " " << id << " - " << average << "  (" << grade << ")  (rank: " << rank << ")" << endl;
}
