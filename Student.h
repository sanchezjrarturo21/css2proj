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

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student
{
  private:
    string name;
    int id;
    double average;
    char grade;
    int rank;
  public:
    Student();
    void setName(string name);
    void setID(int id);
    void setAverage(int average);
    void setGrade(char grade);
    void setRank(int rank);
    string getName() const;
    int getID() const;
    double getAverage() const;
    char getGrade() const;
    int getRank() const;
    void print() const;

};
















#endif
