//#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
double calc_average(vector<double> &s, double m1, double m2, double f);
  int main()
  {
    //vector<Student> course;
    vector<double> scores = {9.5, 7.6, 9.8, 5.4, 1.4};
    double midterm1, midterm2, final, overall_avg;
    midterm1 = 56.3;
    midterm2 = 98.6;
    final = 98.2;
    overall_avg = calc_average(scores, midterm1, midterm2, final);
    cout << overall_avg;
    /*ifstream myfile;
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
    subjects.resize(index);
    while(!myfile.eof() && i < index){
      myfile >> d >> n >> s >> e;
      subjects[i].setDepartment(d);
      subjects[i].setNumber(n);
      subjects[i].setSection(s);
      subjects[i].setStudents(e);
      i++;
    }
    myfile.close();*/

  }
  double calc_average(vector<double> &s, double m1, double m2, double f)
  {
    double s_total = 10.2;
    sort(s.begin(), s.end());
    s[0].clear();
    for(int i = 0; i < s.size(); i++)
    {
      cout << s[i] << " ";
    }
    return s_total;
  }
