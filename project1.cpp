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
  int main()
  {
    string n;
    int d;
    vector<Student> course;
    double score1, score2, score3, score4, score5, midterm1, midterm2, final, overall_avg;
    cout << "nigger";
    ifstream myfile;
    string filepath;
    cout << "Enter file name: ";
    getline(cin, filepath);
    cout << endl;
    myfile.open(filepath.c_str());
    if(myfile.fail())
    {
      cout <<" Failed to open file "<< endl;
      exit(1);
    }
    int index = 0;
    int i = 0;
    myfile >> index;
    course.resize(index);
    while(!myfile.eof() && i < index){
      cout << "nigger";
        myfile >> n >> d >> score1 >> score2 >> score3 >> score4 >> score5 >> midterm1 >> midterm2 >> final;
        cout << "nigger";
        course[i].setName(n);
        course[i].setID(d);
        course[i].setAverage(calc_average(score1, score2, score3, score4, score5, midterm1, midterm2, final));
        i++;
    }
    cout << "nigger";
    myfile.close();
    cout << "nigger";
    label_rank(course);
    cout << "================" << endl;
    cout << "Course Report: Numerical Average Order" << endl;
    cout << "================" << endl;
    a_sort(course);
    cout << "================" << endl;
    cout << "Course Report: First Name Order" << endl;
    cout << "================" << endl;
  }
  double calc_average(double s1, double s2, double s3, double s4, double s5, double m1, double m2, double f)
  {
    vector<double> s = {s1 , s2, s3, s4, s5};
    double s_total, s_average, end_average;
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
    for (int i = i; i < s.size(); i++)
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
      }
    }
    for(int a = 0; a < s.size(); a++){
      s[a].print();
    }
  }
  void n_sort(vector<Student> &s)
  {
    Student avg_Top;
    for (int j = 0; j < s.size() - 1; j++){
      for (int i = j + 1; i < s.size(); i++){
        if (s[j].getName() < s[i].getName()){
          avg_Top = s[j];
          s[j] = s[i];
          s[i] = avg_Top;
        }
      }
    }
    for(int a = 0; a < s.size(); a++){
      s[a].print();
    }
  }
