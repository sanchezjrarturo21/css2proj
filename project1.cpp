#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
double calc_average(vector<double> &s, double m1, double m2, double f);
  int main()
  {
    vector<Student> course;
    vector<double> scores;
    double midterm1, midterm2, final, overall_avg;
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

    }
    myfile.close();

  }
  double calc_average(vector<double> &s, double m1, double m2, double f)
  {
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
