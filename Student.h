#ifndef STUDENT_H
#define STUDENT_H

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
