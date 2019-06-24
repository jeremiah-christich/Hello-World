//*****************************************************************************************************
//
//			File:					LLDriver.cpp
//
//			Student:				Jeremiah Christich
//
//			Course Name:			Data Structures I
//
//			Course Number:			COSC 3050 - 10
//
//			Due:					February 6, 2019
//
//
//			This program acts as a driver for an ordered linked list.
//
//			Other files required: 
//									Node.h
//									LinkedList.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "LinkedList.h"

//*****************************************************************************************************

template <typename T>
void insertions (LinkedList <T> & myList, int & dataIn);
template <typename T>
void displayListValues (const LinkedList <T> &, int & data);

//*****************************************************************************************************

int main()
{
	LinkedList <int> myList;
	int data;

	cout << "Inserting values. . ." << endl;
	insertions (myList, data);

	cout << "Number of nodes: " << myList.getSize() << endl;

	displayListValues (myList, data);

	if (!myList.isEmpty())
		cout << "List is empty." << endl;
	else
		cout << "List is not empty." << endl;

	if (!myList.isFull())
		cout << "List is full." << endl;
	else
		cout << "List is not full." << endl;

	cout << "Clearing list. . ." << endl;
	if (!myList.clearList())
		cout << "List is already empty." << endl;
	else
		cout << "List cleared!" << endl;

	cout << "Number of nodes: " << myList.getSize() << endl;

	cout << "Press Enter to continue. . .";
	cin.get();

	return 0;
}

//*****************************************************************************************************

template <typename T>
void insertions (LinkedList <T> & myList, int & dataIn)
{
	for (int i = 1; i < 8; i++)
	{
		if (!myList.insert(i * 2))
			cout << "Insertion of value " << i * 2 << " did not work." << endl;
	}

	cout << "List: ";
	myList.display();

	dataIn = 5;
	if (!myList.insert(dataIn))
		cout << "Insertion of value " << dataIn << " did not work." << endl;
	else
	{
		cout << "After inserting " << dataIn << ": ";
		myList.display();
	}

	dataIn = -55;

	if (!myList.insert(dataIn))
		cout << "Insertion of value " << dataIn << " did not work." << endl;
	else
	{
		cout << "After inserting " << dataIn << ": ";
		myList.display();
	}
}

//*****************************************************************************************************

template <typename T>
void displayListValues (const LinkedList <T> & myList, int & data)
{
	if (!myList.viewFront(data))
		cout << "Error: No front value exists." << endl;
	else
		cout << "Front value: " << data << endl;

	if (!myList.viewBack(data))
		cout << "Error: No back value exists." << endl;
	else
		cout << "Back value: " << data << endl;

	data = 0;

	cout << "Attempting to retrieve value: " << data << endl;
	if (!myList.retrieve(data))
		cout << "Value not found." << endl;
	else
		cout << "Value found!" << endl;

	data = 14;

	cout << "Attempting to retrieve value: " << data << endl;
	if (!myList.retrieve(data))
		cout << "Value not found." << endl;
	else
		cout << "Value found!" << endl;
}

//*****************************************************************************************************

/*
Inserting values. . .
List: 2 4 6 8 10 12 14
After inserting 5: 2 4 5 6 8 10 12 14
After inserting -55: -55 2 4 5 6 8 10 12 14
Number of nodes: 9
Front value: -55
Back value: 14
Attempting to retrieve value: 0
Value not found.
Attempting to retrieve value: 14
Value found!
List is not empty.
List is not full.
Clearing list. . .
List cleared!
Number of nodes: 0
Press Enter to continue. . .
*/
