//*****************************************************************************************************
//
//		File:			    customer.h
//		
//		Student:			Jeremiah Christich
//
//		Course Name:		Data Structures II  
//
//		Course Number:		COSC 3100 - 11
//
//		Due:			    April 30, 2019 
//
//
//		This header file contains the customer structure and overloaded operators.
//
//		Other files required:
//						 heap.h
//						 WaitList.cpp
//						 overbooked.bin
//		
//*****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//*****************************************************************************************************

struct Customer
{
	char fname[15];
	char lname[15];
	int mileage;
	int years;
	int arrivalNum;
	int priority;

	Customer();
	bool operator == (const Customer &)	const;
	bool operator == (int value)	const;
	bool operator != (const Customer &)	const;
	bool operator != (int value)	const;
	bool operator < (const Customer &)	const;
	bool operator < (int value)	const;
	bool operator <= (const Customer &)	const;
	bool operator <= (int value) const;
	bool operator > (const Customer &)	const;
	bool operator > (int value)	const;
	bool operator >= (const Customer &)	const;
	bool operator >= (int value)	const;
	int operator % (int value)	const;
	Customer & operator = (const Customer &);
	Customer & operator = (int value);
	friend ostream & operator << (ostream &, const Customer &);
	friend istream & operator >> (istream &, Customer &);
};

//*****************************************************************************************************

Customer::Customer()
{
	priority = 0;
}

//*****************************************************************************************************

bool Customer :: operator == (const Customer & rhs)	const
{
	return this->priority == rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator == (int value)	const
{
	return this->priority == value;
}

//*****************************************************************************************************

bool Customer :: operator != (const Customer & rhs)	const
{
	return this->priority != rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator != (int value)	const
{
	return this->priority != value;
}

//*****************************************************************************************************

bool Customer :: operator < (const Customer & rhs)	const
{
	return this->priority < rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator < (int value)	const
{
	return this->priority < value;
}

//*****************************************************************************************************

bool Customer :: operator <= (const Customer & rhs)	const
{
	return this->priority <= rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator <= (int value)	const
{
	return this->priority <= value;
}

//*****************************************************************************************************

bool Customer :: operator > (const Customer & rhs)	const
{
	return this->priority > rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator > (int value)	const
{
	return this->priority > value;
}

//*****************************************************************************************************

bool Customer :: operator >= (const Customer & rhs)	const
{
	return this->priority >= rhs.priority;
}

//*****************************************************************************************************

bool Customer :: operator >= (int value)	const
{
	return this->priority >= value;
}

//*****************************************************************************************************

int Customer :: operator % (int value)	const
{
	return this->priority % value;
}

//*****************************************************************************************************

Customer & Customer :: operator = (const Customer & rhs)
{
	strcpy_s(this->fname, rhs.fname);
	strcpy_s(this->lname, rhs.lname);
	this->mileage = rhs.mileage;
	this->years = rhs.years;
	this->arrivalNum = rhs.arrivalNum;
	this->priority = rhs.priority;

	return *this;
}

//*****************************************************************************************************

Customer & Customer :: operator = (int value)
{
	this->priority = value;

	return *this;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Customer & rhs)
{
	out << right << setw(5) << rhs.priority << "\t\t" << rhs.lname << ", " << rhs.fname << "\t\t\t" 
		<< rhs.mileage << "\t\t\t" << rhs.years << "\t\t\t" << right << setw(2) << rhs.arrivalNum 
		<< endl;

	return out;
}

//*****************************************************************************************************

istream & operator >> (istream & in, Customer & rhs)
{
	in.ignore();
	in.getline(rhs.fname, 15);
	in.getline(rhs.lname, 15);
	in >> rhs.mileage
		>> rhs.years
		>> rhs.arrivalNum;

	return in;
}

//*****************************************************************************************************

#endif