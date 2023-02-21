#include <iostream>
#include <string>

using namespace std;

struct student {
  int rollNo;
  string Name;
  int age;
  string st_class;
  int grade;
} s1first, s1last, s2first, s2last;

int main()
{
  string space;

  s1first.rollNo = 1;
    s1last.rollNo = 1;
  s1first.Name = "Carl";
    s1last.Name = "Carl";
  s1last.Name = "Wheezer";
    s1last.Name = "Wheezer";
  s1first.age = 17;
    s1last.age = 17;
  s1first.st_class = "Physics";
    s1last.st_class = "Physics";
  s1first.grade = 87;
    s1last.grade = 87;

  cout << "Enter roll number of student 2: ";
  cin >> s2first.rollNo;
    s2last.rollNo = s2first.rollNo;
  cin.ignore(1, '\n');
  cout << "Enter first name of student 2: ";
  getline(cin, s2first.Name);
  cout << "Enter last name of stduent 2: ";
  getline(cin, s2last.Name);
  cout << "Enter age of student 2: ";
  cin >> s2first.age;
    s2last.age = s2first.age;
  cin.ignore(1, '\n');
  cout << "Enter class of student 2: ";
  getline(cin, s2first.st_class);
    s2last.st_class = s2first.st_class;
  cout << "Enter grade of student 2: ";
  cin >> s2first.grade;
    s2last.grade = s2first.grade;


  cout << endl;
  cout << "Student 1: " << endl;
  cout << "Roll Number: " << s1first.rollNo << endl;
  cout << "Name: " << s1first.Name << " " << s1last.Name << endl;
  cout << "Age: " << s1first.age << endl;
  cout << "Class: " << s1first.st_class << endl;
  cout << "Grade: " << s1first.grade << endl;

  cout << endl;
  cout << "Student 2: " << endl;
  cout << "Roll Number: " << s2first.rollNo << endl;
  cout << "Name: " << s2first.Name << " " << s2last.Name << endl;
  cout << "Age: " << s2first.age << endl;
  cout << "Class: " << s2first.st_class << endl;
  cout << "Grade: " << s2first.grade << endl;

  cout << endl;
}
