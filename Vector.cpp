//*****************************************************************************************************
//
//		File:			    Vector.cpp
//		
//		Student:			Jeremiah Christich
//
//		Course Name:		Data Structures II  
//
//		Course Number:		COSC 3100 - 11
//
//		Due:			    April 29, 2019 
//
//
//		This program demonstrates the different functions in a vector 
//		by inserting student records from a text file.
//
//		Other files required:
//						 student.h
//						 smallStudentFile.txt
//		
//*****************************************************************************************************

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
#include "student.h"

//*****************************************************************************************************

char getChoice();
void addStudent(vector <Student> & studentList);
void searchStudent(vector <Student> & studentList);
void processFile(vector <Student> & studentList);
void removeStudent(vector <Student> & studentList);
void testVector(vector <Student> & studentList);
void displayList(vector <Student> & studentList);
void displayListRev(const vector <Student> & studentList);
void displayStats(vector <Student> & studentList);
void display1Student(Student & stu);

//*****************************************************************************************************

int main ()
{
	vector <Student> studentList;
	Student stu;
	char choice;

	do
	{
		cout << "======== MENU ========\n"
			<< " A:  Add a new Student \n"
			<< " S:  Search a Student Record \n"
			<< " F:  Fill List \n"
			<< " D:  Delete a Student Record \n"
			<< " P:  Print List \n"
			<< " T:  Test Vector \n"
			<< " X:  List Stats\n"
			<< " Q:  Quit \n\n";

		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(studentList);
				break;
		case 'S': searchStudent(studentList);
				break;
		case 'F': processFile(studentList);
				break;
		case 'D': removeStudent(studentList);
				break;
		case 'T': testVector(studentList);
				break;
		case 'P': displayList(studentList);
				  displayListRev(studentList);
				break;
		case 'X': displayStats(studentList);
				break;
		}

		cout << endl;
	} while (choice != 'Q');

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	bool valid;
	char option;

	do
	{
		cout << "Select an option: ";
		cin >> option;

		switch (toupper(option))
		{
		case 'A': valid = true;
			break;
		case 'S': valid = true;
			break;
		case 'F': valid = true;
			break;
		case 'D': valid = true;
			break;
		case 'P': valid = true;
			break;
		case 'X': valid = true;
			break;
		case 'T': valid = true;
			break;
		case 'Q': valid = true;
			break;
		default:
			cout << "Not a valid option." << endl;
			valid = false;
			break;
		}

	} while (!valid);

	return toupper(option);
}

//*****************************************************************************************************

void processFile(vector <Student> & studentList)
{
	Student stu;
	ifstream file;

	file.open("smallStudentFile.txt");

	while (file >> stu)
	{
		studentList.push_back(stu);
	}

	file.close();
	
	stable_sort(studentList.begin(), studentList.end());
	displayList(studentList);

	cout << "Shrinking vector to fit..." << endl;
	studentList.shrink_to_fit();
}

//*****************************************************************************************************

void addStudent(vector <Student> & studentList)
{
	Student nStudent;
	vector <Student>::iterator it;

	it = studentList.end();

	cout << "\n========  Add New Student Record ======== \n"
		<< "Student ID: ";
	cin >> nStudent.id;
	cin.ignore();
	cout << "Student Name: ";
	cin.getline(nStudent.name, 50);
	cout << "Student City, State: ";
	cin.getline(nStudent.citystate, 50);
	cout << "Gender: ";
	cin >> nStudent.gender;
	cout << "Year: ";
	cin >> nStudent.year;
	cout << "Credit hours: ";
	cin >> nStudent.credits;
	cout << "GPA: ";
	cin >> nStudent.gpa;
	cout << "Major: ";
	cin >> nStudent.major;

	studentList.insert(it, nStudent);
	sort(studentList.begin(), studentList.end());

	cout << "\n======== Student Record ======== \n";
	cout << setw(15) << left << "Student ID: " << nStudent.id << endl;
	cout << setw(15) << left << "Student Name: " << nStudent.name << endl;
	cout << setw(15) << left << "City, State: " << nStudent.citystate << endl;
	cout << setw(15) << left << "Gender: " << nStudent.gender << endl;
	cout << setw(15) << left << "Year: " << nStudent.year << endl;
	cout << setw(15) << left << "Credit hours: " << nStudent.credits << endl;
	cout << setw(15) << left << "GPA: " << nStudent.gpa << endl;
	cout << setw(15) << left << "Major: " << nStudent.major << endl;
	cout << "\nStudent added!" << endl;
}

//*****************************************************************************************************

void searchStudent(vector <Student> & studentList)
{
	Student nStudent;
	vector <Student>::iterator it;

	cout << "\n========  Find Student Record ======== \n"
		<< "Student ID: ";
	cin >> nStudent.id;

	it = find(studentList.begin(), studentList.end(), nStudent.id);

	if (it != studentList.end())
	{
		cout << "Student found!" << endl;
		cout << * it << endl;
	}
	else
		cout << "Student not found!" << endl;
}

//*****************************************************************************************************

void removeStudent(vector <Student> & studentList)
{
	Student tempStudent;
	vector <Student>::iterator it;

	cout << "\n========  Remove Student ======== \n"
		<< "Student ID: ";
	cin >> tempStudent.id;

	it = find(studentList.begin(), studentList.end(), tempStudent.id);

	if (it != studentList.end())
	{
		cout << "Student file erased!" << endl;
		cout << * it << endl;
		studentList.erase(it);
	}
	else
		cout << "Student not found!" << endl;
}

//*****************************************************************************************************

void testVector(vector <Student> & studentList)
{
	vector <Student>::iterator it;
	
	if (!studentList.empty())
	{
		cout << "\n========== Testing Student Container  =============" << endl;
		cout << "Adding Two to size..." << endl;
		studentList.resize(studentList.size() + 2);

		cout << "Erasing back 2 elements..." << endl;
		it = (studentList.end() - 2);
		studentList.erase(it, studentList.end());

		cout << "Reversing list..." << endl;
		reverse(studentList.begin(), studentList.end());

		displayList(studentList);

		cout << "Popping back..." << endl;
		studentList.pop_back();

		cout << "Erasing front..." << endl;
		studentList.erase(studentList.begin());

		displayList(studentList);

		cout << "Calling clear..." << endl;
		studentList.clear();
	}
	else
		cout << "Vector is empty..." << endl;
}

//*****************************************************************************************************

void displayList(vector <Student> & studentList)
{
	cout << "\n============ Student Records List ==============" << endl;
	cout << "  ID \t Name \t\t\t Major  GPA  Year\n";
	cout << "=================================================\n";

	for_each(studentList.begin(), studentList.end(), display1Student);

	cout << "================ End of List ===================\n" << endl;
}

//*****************************************************************************************************

void display1Student(Student & stu)
{
	cout << stu << endl;
}

//*****************************************************************************************************

void displayListRev(const vector <Student> & studentList)
{
	cout << "\n======== Student Records Reverse List ===========" << endl;
	cout << "  ID \t Name \t\t\t Major  GPA  Year\n";
	cout << "=================================================\n";

	for (int j = studentList.size(); j > 0; j--)
	{
		cout << studentList[j - 1] << endl;
	}

	cout << "================ End of List ===================\n" << endl;
}

//*****************************************************************************************************

void displayStats(vector <Student> & studentList)
{
	vector <Student>::iterator it;

	cout << "============== Stats ===============" << endl;
	cout << "Size " << studentList.size() << endl;
	cout << "Capacity: " << studentList.capacity() << endl;
	cout << "Max size: " << studentList.max_size() << endl;
	cout << "Empty: ";

	if (studentList.empty())
		cout << "Yes" << endl;
	else
	{
		cout << "No" << endl;

		cout << left << setw(20) << "Front: " << right << studentList.front() << endl;
		cout << left << setw(20) << "Back:  " << right << studentList.back() << endl;

		it = min_element(studentList.begin(), studentList.end());
		cout << left << setw(20) << "Minimum element: " << right << *it << endl;

		it = max_element(studentList.begin(), studentList.end());
		cout << left << setw(20) << "Maximum element: " << right << *it << endl;

		cout << "\n=========== Student Records List ================" << endl;
		cout << "  ID \t Name \t\t\t Major  GPA  Year\n";
		cout << "=================================================\n";

		for (int j = 0; j < studentList.size(); j++)
		{
			cout << studentList.at(j) << endl;
		}

		cout << "================ End of List ===================\n" << endl;
	}
		
}

//*****************************************************************************************************

/*
======== MENU ========
 A:  Add a new Student
 S:  Search a Student Record
 F:  Fill List
 D:  Delete a Student Record
 P:  Print List
 T:  Test Vector
 X:  List Stats
 Q:  Quit

Select an option: f

============ Student Records List ==============
  ID     Name                    Major  GPA  Year
=================================================
 9743  Johnson, James L           ENGR  3.15  1
17424  Nakamura, Toky O           SOCI  1.95  1
18264  Lucky, Lucy L              HIST  2.29  5
24237  Euler, Lennie L            MATH  3.83  1
31631  Aristotle, Alice A         PHIL  3.10  3
================ End of List ===================

Shrinking vector to fit...

======== MENU ========
 A:  Add a new Student
 S:  Search a Student Record
 F:  Fill List
 D:  Delete a Student Record
 P:  Print List
 T:  Test Vector
 X:  List Stats
 Q:  Quit

Select an option: d

========  Remove Student ========
Student ID: 24237
Student file erased!
24237  Euler, Lennie L            MATH  3.83  1

======== MENU ========
 A:  Add a new Student
 S:  Search a Student Record
 F:  Fill List
 D:  Delete a Student Record
 P:  Print List
 T:  Test Vector
 X:  List Stats
 Q:  Quit

Select an option: x
============== Stats ===============
Size 4
Capacity: 5
Max size: 30678337
Empty: No
Front:               9743  Johnson, James L           ENGR  3.15  1
Back:               31631  Aristotle, Alice A         PHIL  3.10  3
Minimum element:     9743  Johnson, James L           ENGR  3.15  1
Maximum element:    31631  Aristotle, Alice A         PHIL  3.10  3

=========== Student Records List ================
  ID     Name                    Major  GPA  Year
=================================================
 9743  Johnson, James L           ENGR  3.15  1
17424  Nakamura, Toky O           SOCI  1.95  1
18264  Lucky, Lucy L              HIST  2.29  5
31631  Aristotle, Alice A         PHIL  3.10  3
================ End of List ===================


======== MENU ========
 A:  Add a new Student
 S:  Search a Student Record
 F:  Fill List
 D:  Delete a Student Record
 P:  Print List
 T:  Test Vector
 X:  List Stats
 Q:  Quit

Select an option: t

========== Testing Student Container  =============
Adding Two to size...
Erasing back 2 elements...
Reversing list...

============ Student Records List ==============
  ID     Name                    Major  GPA  Year
=================================================
31631  Aristotle, Alice A         PHIL  3.10  3
18264  Lucky, Lucy L              HIST  2.29  5
17424  Nakamura, Toky O           SOCI  1.95  1
 9743  Johnson, James L           ENGR  3.15  1
================ End of List ===================

Popping back...
Erasing front...

============ Student Records List ==============
  ID     Name                    Major  GPA  Year
=================================================
18264  Lucky, Lucy L              HIST  2.29  5
17424  Nakamura, Toky O           SOCI  1.95  1
================ End of List ===================

Calling clear...

======== MENU ========
 A:  Add a new Student
 S:  Search a Student Record
 F:  Fill List
 D:  Delete a Student Record
 P:  Print List
 T:  Test Vector
 X:  List Stats
 Q:  Quit

Select an option:
*/