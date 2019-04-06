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
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
double calc_average(double s1, double s2, double s3, double s4, double s5, double m1, double m2, double f);
void label_rank(vector<Student> &s);
void a_sort(vector<Student> &s);
void n_sort(vector<Student> &s);
double class_avg(vector<Student> &s);
void histogram(vector<Student> &s);
void rec_finder(vector<Student> &s);
  int main()
  {
    string n;
    int d;
    vector<Student> course;
    double score1, score2, score3, score4, score5, midterm1, midterm2, final, overall_avg;
    ifstream myfile;
    string filepath;
// user enters in file path
    cout << "Enter file name: ";
    getline(cin, filepath);
    cout << endl;
    myfile.open(filepath.c_str());
// if file can't be found an error message is displayed
    if(myfile.fail())
    {
      cout <<" Failed to open file "<< endl;
      exit(1);
    }
    int index = 0;
    int i = 0;
// reads from file and inputs the information from each line into an object
    myfile >> index;
    course.resize(index);
    while(!myfile.eof() && i < index){
        myfile >> n >> d >> score1 >> score2 >> score3 >> score4 >> score5 >> midterm1 >> midterm2 >> final;
        course[i].setName(n);
        course[i].setID(d);
        course[i].setAverage(calc_average(score1, score2, score3, score4, score5, midterm1, midterm2, final));
        i++;
    }
    myfile.close();


    label_rank(course);
    cout << "================" << endl;
    cout << "Course Report: Numerical Average Order" << endl;
    cout << "================" << endl;

// calls function a_sort that sorts students by average
    a_sort(course);
    cout << "================" << endl;
    cout << "Course Report: First Name Order" << endl;
    cout << "================" << endl;

// calls function n_sort that sorts students by first name
    n_sort(course);
    cout << "================" << endl;
    cout << endl;
    cout << "================" << endl;
    cout << "Statistics" << endl;
    cout << "================" << endl;
    cout << "Number of students: " << index << endl;
// calls function class_avg that calculates the class average and ouputs
    cout << "Class Average: " << class_avg(course) << endl;
// calls function histogram that prints out grade distribution
    cout << "Grade Distribution (histogrampy)" << endl;
    histogram(course);
    cout << "================" << endl;
    cout << endl;
    cout << "================" << endl;

// calls function rec_finder that finds a student in a course
    rec_finder(course);

  }


// function calculates average for a given student
  double calc_average(double s1, double s2, double s3, double s4, double s5, double m1, double m2, double f)
  {
    vector<double> s = {s1 , s2, s3, s4, s5};
    double s_total = 0, s_average = 0, end_average = 0;
    sort(s.rbegin(), s.rend());
    s.pop_back();
    for(int i = 0; i < s.size(); i++)
    {
      s_total += s[i];
    }
    s_average = (s_total / s.size()) / 10.0;
    end_average = (s_total * .20) + (m1 * .20) + (m2 * .20) + (f * .40);

    return end_average;
  }

// funtion ranks students
  void label_rank(vector<Student> &s)
  {
    int rank = 2;
    Student avg_Top;
    for (int j = 0; j < s.size() - 1; j++){
      for (int i = j + 1; i < s.size(); i++){
        if (s[j].getAverage() < s[i].getAverage()){
          avg_Top = s[j];
          s[j] = s[i];
          s[i] = avg_Top;
        }
      }
    }
    s[0].setRank(1);
    for (int i = 1; i < s.size(); i++)
    {
      if (s[i].getAverage() < s[i-1].getAverage())
      {
        s[i].setRank(rank);
      }
      else if (s[i].getAverage() == s[i-1].getAverage())
      {
        s[i].setRank(s[i-1].getRank());
      }
      rank++;
    }
  }

// funtion sorts students by average
  void a_sort(vector<Student> &s)
  {
    Student avg_Top;
    for (int j = 0; j < s.size() - 1; j++){
      for (int i = j + 1; i < s.size(); i++){
        if (s[j].getAverage() < s[i].getAverage()){
          avg_Top = s[j];
          s[j] = s[i];
          s[i] = avg_Top;
        }
        else if (s[j].getAverage() == s[i].getAverage()){
          if (s[j].getID() < s[i].getID()){
            avg_Top = s[j];
            s[j] = s[i];
            s[i] = avg_Top;
          }
        }
      }
    }
    for(int a = 0; a < s.size(); a++){
      s[a].print();
    }
  }

  // fuction sorts sudents by first name
  void n_sort(vector<Student> &s)
  {
    Student avg_Top;
    for (int j = 0; j < s.size() - 1; j++){
      for (int i = j + 1; i < s.size(); i++){
        if (s[j].getName() > s[i].getName()){
          avg_Top = s[j];
          s[j] = s[i];
          s[i] = avg_Top;
        }
        else if (s[j].getName() == s[i].getName()){
          if (s[j].getID() < s[i].getID()){
            avg_Top = s[j];
            s[j] = s[i];
            s[i] = avg_Top;
          }
        }
      }
    }
    for(int a = 0; a < s.size(); a++){
      s[a].print();
    }
  }

  // function calculates class average
  double class_avg(vector<Student> &s)
  {
    double c_total = 0, c_average = 0;
    for(int i = 0; i < s.size(); i++){
      c_total += s[i].getAverage();
    }
    c_average = c_total / s.size();
    return c_average;

  }

  // function creates histogram
  void histogram(vector<Student> &s)
  {
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, f_count = 0;
    for (int i = 0; i < s.size(); i++){
      if(s[i].getGrade() == 'A'){
        a_count++;
      }
      if(s[i].getGrade() == 'B'){
        b_count++;
      }
      if(s[i].getGrade() == 'C'){
        c_count++;
      }
      if(s[i].getGrade() == 'D'){
        d_count++;
      }
      if(s[i].getGrade() == 'D'){
        f_count++;
      }
    }
    cout << "A ";
    for(int i = 0; i < a_count; i++){
      cout << "* ";
    }
    cout << endl;
    cout << "B ";
    for(int i = 0; i < b_count; i++){
      cout << "* ";
    }
    cout << endl;
    cout << "C ";
    for(int i = 0; i < c_count; i++){
      cout << "* ";
    }
    cout << endl;
    cout << "D ";
    for(int i = 0; i < d_count; i++){
      cout << "* ";
    }
    cout << endl;
    cout << "F ";
    for(int i = 0; i < f_count; i++){
      cout << "* ";
    }
    cout << endl;
  }

  // function allows user to search for a specific student
  void rec_finder(vector<Student> &s)
  {
     char opt;
     string find_student;
     bool student_found = false;
    do{
      cout << "Record Finder: Enter the name of a student: ";
      cin >> find_student;
      cout << "================" << endl;
      for(int i = 0; i < s.size(); i++){
        if (s[i].getName() == find_student){
          student_found = true;
          s[i].print();
          cout<<endl;
          cout << "================" << endl;
        }

        }
      if(student_found == false){
        cout << "Failed. " << find_student << " is not enrolled in the class." << endl;
      }

      cout << "Do you want to continue? (y/n): ";
      cin >> opt;
      opt = toupper(opt);
      if (opt == 'N'){
        cout << "================" << endl;
        cout << "Done."<< endl;
      }
    }
    while( opt == 'Y');
  }
