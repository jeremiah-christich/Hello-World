//*****************************************************************************************************
//
//		File:			    student.h
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
//		This program consists of the Student structure and overloaded operators
//
//		Other files required:
//                       Vector.cpp
//						 smallStudentFile.txt
//		
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	bool operator == (const Student &)	const;
	bool operator == (int value)	const;
	bool operator != (const Student &)	const;
	bool operator != (int value)	const;
	bool operator < (const Student &)	const;
	bool operator < (int value)	const;
	bool operator <= (const Student &)	const;
	bool operator <= (int value) const;
	bool operator > (const Student &)	const;
	bool operator > (int value)	const;
	bool operator >= (const Student &)	const;
	bool operator >= (int value)	const;
	int operator % (int value)	const;
	Student & operator = (const Student &);
	Student & operator = (int value);
	friend ostream & operator << (ostream &, const Student &);
	friend istream & operator >> (istream &, Student &);
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

bool Student :: operator == (const Student & rhs)	const
{
	return this->id == rhs.id;
}

//*****************************************************************************************************

bool Student :: operator == (int value)	const
{
	return this->id == value;
}

//*****************************************************************************************************

bool Student :: operator != (const Student & rhs)	const
{
	return this->id != rhs.id;
}

//*****************************************************************************************************

bool Student :: operator != (int value)	const
{
	return this->id != value;
}

//*****************************************************************************************************

bool Student :: operator < (const Student & rhs)	const
{
	return this->id < rhs.id;
}

//*****************************************************************************************************

bool Student :: operator < (int value)	const
{
	return this->id < value;
}

//*****************************************************************************************************

bool Student :: operator <= (const Student & rhs)	const
{
	return this->id <= rhs.id;
}

//*****************************************************************************************************

bool Student :: operator <= (int value)	const
{
	return this->id <= value;
}

//*****************************************************************************************************

bool Student :: operator > (const Student & rhs)	const
{
	return this->id > rhs.id;
}

//*****************************************************************************************************

bool Student :: operator > (int value)	const
{
	return this->id > value;
}

//*****************************************************************************************************

bool Student :: operator >= (const Student & rhs)	const
{
	return this->id >= rhs.id;
}

//*****************************************************************************************************

bool Student :: operator >= (int value)	const
{
	return this->id >= value;
}

//*****************************************************************************************************

int Student :: operator % (int value)	const
{
	return this->id % value;
}

//*****************************************************************************************************

Student & Student :: operator = (const Student & rhs)
{
	this->id = rhs.id;
	strcpy(this->name, rhs.name);
	strcpy(this->citystate, rhs.citystate);
	strcpy(this->phone, rhs.phone);
	this->gender = rhs.gender;
	this->year = rhs.year;
	this->credits = rhs.credits;
	this->gpa = rhs.gpa;
	strcpy(this->major, rhs.major);

	return * this;
}

//*****************************************************************************************************

Student & Student :: operator = (int value)
{
	this->id = value;

	return * this;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Student & rhs)
{
	out << setprecision(2) << fixed;
	out << right << setw(5) << rhs.id << "  " << left << setw(27) << rhs.name << setw(6) << rhs.major
		<< setw(6) << rhs.gpa << rhs.year;

	return out;
}

//*****************************************************************************************************

istream & operator >> (istream & in, Student & rhs)
{
	in >> rhs.id;
	in.ignore();
	in.getline(rhs.name, 50);
	in.getline(rhs.citystate, 50);
	in >> rhs.phone
	   >> rhs.gender
	   >> rhs.year
	   >> rhs.credits
	   >> rhs.gpa
	   >> rhs.major;

	return in;
}

//*****************************************************************************************************

#endif