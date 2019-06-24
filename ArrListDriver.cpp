//*****************************************************************************************************
//
//			File:					ArrListDriver.cpp
//
//			Student:				Jeremiah Christich
//
//			Course Name:			Data Structures I
//
//			Course Number:			COSC 3050 - 10
//
//			Due:					January 30, 2019
//
//
//			This program acts as the driver for an Array List.
//
//			Other files required: 
//									ArrList.h
//
//*****************************************************************************************************

using namespace std;
#include "ArrList.h"

//*****************************************************************************************************

template <typename T>
void displayInserts (ArrList <T> & arr);
template <typename T>
void displayUpdates (ArrList <T> & arr);
template <typename T>
void displayRetrievals (const ArrList <T> & arr, T & dataOut);
template <typename T>
void displayRemovals (ArrList <T> & arr, T & dataOut);
template <typename T>
void displayFind(const ArrList <T> & arr);

//*****************************************************************************************************

int main()
{
	ArrList <short> arr;
	short dataOut;

	cout << "================= Initially =================" << endl;
	cout << "Number of values in the list: " << arr.getNumValues() << endl;
	cout << "Capacity: " << arr.getCapacity() << endl;
	cout << "Is array empty? ";
	if (!arr.isEmpty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << "\n======== Inserting values into the list ========" << endl;
	displayInserts (arr);

	cout << "\n================== Updates ==================" << endl;
	displayUpdates (arr);

	cout << "\n================= Retrievals =================" << endl;
	displayRetrievals (arr, dataOut);

	cout << "\n================== Removals ==================" << endl;
	displayRemovals (arr, dataOut);

	cout << "\n===================== Find ===================" << endl;
	displayFind(arr);

	cout << "\n==================== Finally ==================" << endl;
	cout << "Clearing list. . ." << endl;
	arr.clearList();
	cout << "Number of values in the list: " << arr.getNumValues() << endl;
	cout << "Capacity: " << arr.getCapacity() << endl;
	cout << "Is array empty? ";

	if (!arr.isEmpty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

//*****************************************************************************************************

template <typename T>
void displayInserts (ArrList <T> & arr)
{
	cout << "Inserting values at back: ";
	for (int i = 0; i < 6; i++)
	{
		if (!arr.insertBack(5 * i))
			cout << "Values were not successfully inserted at back." << endl;
	}
	arr.displayArr();

	cout << "Trimming array to number of values. . ." << endl;
	arr.trimToSize();

	cout << "Number of values in the list: " << arr.getNumValues() << endl;
	cout << "Capacity: " << arr.getCapacity() << endl;
	
	cout << "Inserting value -55 at front: ";
	if (!arr.insertFront(-55))
		cout << "Value were not successfully inserted at front." << endl;
	arr.displayArr();

	cout << "Inserting value 11 at Index 5: ";
	if (!arr.insertAtIndex(11, 5))
		cout << "Value was not successfully inserted at index." << endl;
	arr.displayArr();

	cout << "Number of values in the list: " << arr.getNumValues() << endl;
	cout << "Capacity: " << arr.getCapacity() << endl;
}

//*****************************************************************************************************

template <typename T>
void displayUpdates (ArrList <T> & arr)
{
	cout << "Updating value 5 in list: ";
	if (!arr.update(5))
		cout << "Value was not successfully updated." << endl;
	arr.displayArr();

	cout << "Updating value at Front to 9: ";
	if (!arr.updateFront(9))
		cout << "Value was not successfully updated." << endl;
	arr.displayArr();

	cout << "Updating value at Back to -33: ";
	if (!arr.updateBack(-33))
		cout << "Value was not successfully updated." << endl;
	arr.displayArr();

	cout << "Updating value at Index 4 to 89: ";
	if (!arr.updateAtIndex(89, 4))
		cout << "Value was not successfully updated." << endl;
	arr.displayArr();
}

//*****************************************************************************************************

template <typename T>
void displayRetrievals (const ArrList <T> & arr, T & dataOut)
{
	dataOut = 20;
	cout << "Retrieving value 20. . ." << endl;
	if (!arr.retrieve(dataOut))
		cout << "Value could not be found" << endl;
	else
		cout << "Value 20 found at index: " << dataOut << endl;

	//Attempt to retrieve value that does not exist
	cout << "Retrieving value at Index 9. . ." << endl;
	if (!arr.retrieveAtIndex(dataOut, 9))
		cout << "Could not retrieve data" << endl;
	else
		cout << "Retrieved value: " << dataOut << endl;

	cout << "Retrieving value at Index 5. . ." << endl;
	if (!arr.retrieveAtIndex(dataOut, 5))
		cout << "Could not retrieve data" << endl;
	else
		cout << "Retrieved value: " << dataOut << endl;

	cout << "Retrieving value at Front. . ." << endl;
	if (!arr.retrieveFront(dataOut))
		cout << "Could not retrieve data" << endl;
	else
		cout << "Retrieved value: " << dataOut << endl;

	cout << "Retrieving value at Back. . ." << endl;
	if (!arr.retrieveBack(dataOut))
		cout << "Could not retrieve data" << endl;
	else
		cout << "Retrieved value: " << dataOut << endl;

	if (!arr.getBiggest(dataOut))
		cout << "ERROR: Could not find biggest." << endl;
	else
		cout << "Biggest = " << dataOut << endl;
}

//*****************************************************************************************************

template <typename T>
void displayRemovals (ArrList <T> & arr, T & dataOut)
{
	cout << "Removing front value. . ." << endl;
	if (!arr.removeFront(dataOut))
		cout << "Value was not removed." << endl;
	else
		cout << "Removed value: " << dataOut << endl;

	cout << "List: ";
	arr.displayArr();

	cout << "Removing value at Index 3. . ." << endl;
	if (!arr.removeAtIndex(dataOut, 3))
		cout << "Value was not removed." << endl;
	else
		cout << "Removed value: " << dataOut << endl;

	cout << "List: ";
	arr.displayArr();

	cout << "Number of values in the list: " << arr.getNumValues() << endl;
	cout << "Capacity: " << arr.getCapacity() << endl;

	if (!arr.getBiggest(dataOut))
		cout << "ERROR: Could not find biggest." << endl;
	else
		cout << "Biggest = " << dataOut << endl;
}

//*****************************************************************************************************

template <typename T>
void displayFind(const ArrList <T> & arr)
{
	int found;

	cout << "Trying to find value 11. . ." << endl;
	found = arr.find(11);

	if (found == -1)
		cout << "Not found!" << endl;
	else
		cout << "Found at Index " << found << endl;

	cout << "Trying to find value 89. . ." << endl;
	found = arr.find(89);

	if (found == -1)
		cout << "Not found!" << endl;
	else
		cout << "Found at Index " << found << endl;
}

//*****************************************************************************************************

/*
================= Initially =================
Number of values in the list: 0
Capacity: 5
Is array empty? Yes

======== Inserting values into the list ========
Inserting values at back: 0 5 10 15 20 25
Trimming array to number of values. . .
Number of values in the list: 6
Capacity: 6
Inserting value -55 at front: -55 0 5 10 15 20 25
Inserting value 11 at Index 5: -55 0 5 10 15 11 20 25
Number of values in the list: 8
Capacity: 9

================== Updates ==================
Updating value 5 in list: -55 0 6 10 15 11 20 25
Updating value at Front to 9: 9 0 6 10 15 11 20 25
Updating value at Back to -33: 9 0 6 10 15 11 20 -33
Updating value at Index 4 to 89: 9 0 6 10 89 11 20 -33

================= Retrievals =================
Retrieving value 20. . .
Value 20 found at index: 6
Retrieving value at Index 9. . .
Could not retrieve data
Retrieving value at Index 5. . .
Retrieved value: 11
Retrieving value at Front. . .
Retrieved value: 9
Retrieving value at Back. . .
Retrieved value: -33
Biggest = 89

================== Removals ==================
Removing front value. . .
Removed value: 9
List: 0 6 10 89 11 20 -33
Removing value at Index 3. . .
Removed value: 89
List: 0 6 10 11 20 -33
Number of values in the list: 6
Capacity: 9
Biggest = 20

===================== Find ===================
Trying to find value 11. . .
Found at Index 3
Trying to find value 89. . .
Not found!

==================== Finally ==================
Clearing list. . .
Number of values in the list: 0
Capacity: 9
Is array empty? Yes
Press any key to continue . . .
*/
