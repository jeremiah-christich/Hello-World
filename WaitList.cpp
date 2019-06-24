//*****************************************************************************************************
//
//		File:			    WaitList.cpp
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
//		This is program reads the binary file, "overbooked.bin" and outputs a text file 
//		for the overbooked flight list in order of priority.
//
//		Other files required:
//						 heap.h
//						 customer.h
//						 overbooked.bin
//		
//*****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
using namespace std;
#include "customer.h"
#include "heap.h"

//*****************************************************************************************************

void getData(Heap <Customer> & waitList);
void printWaitList(Heap <Customer> & waitList);

//*****************************************************************************************************

int main()
{
	Heap <Customer> waitList;
	getData(waitList);
	printWaitList(waitList);

	return 0;
}

//*****************************************************************************************************

void getData(Heap <Customer> & waitList)
{
	Customer cust;
	ifstream inFile;
	inFile.open("overbooked.bin", ios::binary);

	while (inFile.read((char *) & cust, sizeof(cust)))
	{
		cust.priority = (cust.mileage / 1000) + cust.years - cust.arrivalNum;
		waitList.insert(cust);
	}

	inFile.close();
}

//*****************************************************************************************************

void printWaitList(Heap <Customer> & waitList)
{
	Customer cust;
	ofstream outFile;
	outFile.open("WaitList.txt");

	outFile << "\t Flight \t\t\t    Destination \t\t\t     Time\n"
			<< "American Airlines AA123  \t   St.Louis to Dallas-Fort Worth \t\t    9:17 PM\n\n"
			<< "Priority     Last Name/First Name \t Frequent Flier Miles \t Frequent Flier Years \t"
			<< "Arrival Number \n";

	while (waitList.remove(cust))
		outFile << cust;

	outFile.close();
}

//*****************************************************************************************************