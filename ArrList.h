//*****************************************************************************************************
//
//			File:					ArrList.h
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
//			This program implements an Array List.
//
//			Other files required: 
//									ArrListDriver.cpp
//
//*****************************************************************************************************

#ifndef ARRLIST_H
#define ARRLIST_H
#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class ArrList
{
private:
	T * list;
	int capacity;
	int numValues;
	bool _resize();

public:
	ArrList (int c = 5);
	~ArrList();
	void displayArr ()	const;
	bool insertBack (const T & dataIn);
	bool insertFront (const T & dataIn);
	bool insertAtIndex (const T & dataIn, const int & index);
	bool update (const T &);
	bool updateFront (const T & dataOut);
	bool updateBack (const T & dataOut);
	bool updateAtIndex (const T & dataOut, const int & index);
	bool retrieve (T & dataOut)	const;
	bool retrieveAtIndex (T & dataOut, const int & index)	const;
	bool retrieveFront (T & dataOut) const;
	bool retrieveBack (T & dataOut)	const;
	bool removeFront (T & dataOut);
	bool removeAtIndex (T & dataOut, const int & index);
	void trimToSize();
	void clearList();
	bool getBiggest (T & dataOut)	const;
	bool isEmpty()	const;
	int getCapacity()	const;
	int getNumValues()	const;
	int find(const T & dataIn)	const;
};

//*****************************************************************************************************

template <typename T>
ArrList <T> ::ArrList(int c)
{
	capacity = c;
	numValues = 0;
	list = new (nothrow) T [capacity];
}

//*****************************************************************************************************

template <typename T>
ArrList <T> ::~ArrList()
{
	delete[] list;
	capacity = numValues = 0;
	list = nullptr;
}

//*****************************************************************************************************

template <typename T>
void ArrList <T> :: displayArr() const
{;
	for (int i = 0; i < numValues; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: _resize()
{
	bool success = true;
	capacity += capacity / 2;
	T * temp = new (nothrow) T [capacity];

	if (temp == nullptr)
		success = false;

	else
	{
		for (int i = 0; i < numValues; i++)
		{
			temp[i] = list[i];
		}
		delete [] list;
		list = temp;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: insertBack (const T & dataIn)
{
	bool success = true;
	
	if (numValues == capacity)
		success = _resize();

	if (success == true)
	{
		list[numValues] = dataIn;
		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> ::insertFront (const T & dataIn)
{
	bool success = true;

	if (numValues == capacity)
		success = _resize();

	if (success == true)
	{
		for (int i = numValues; i >= 0; i--)
		{
			list[i] = list[i - 1];
		}

		list[0] = dataIn;
		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: insertAtIndex (const T & dataIn, const int & index)
{
	bool success = false;

	if (index <= numValues && index >= 0)
		success = true;

	if (numValues == capacity)
		success = _resize();

	if (success == true)
	{
		for (int i = numValues; i > index; i--)
		{
			list[i] = list[i - 1];
		}

		list[index] = dataIn;
		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: update (const T & dataOut)
{
	bool success = false;
	T data = dataOut + 1;

	if (numValues > 0)
	{
		for (int i = 0; (!success) && (i < numValues); i++)
		{
			if (dataOut == list[i])
			{
				list[i] = data;
				success = true;
			}
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: updateFront (const T & dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		list[0] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: updateBack (const T & dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		list[numValues - 1] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: updateAtIndex (const T & dataIn, const int & index)
{
	bool success = false;

	if (index <= (numValues - 1) && index >= 0)
	{
		list[index] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: retrieve (T & dataOut)	const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int index = 0; index < numValues; index++)
		{
			if (list[index] == dataOut)
			{
				dataOut = index;
				success = true;
			}
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: retrieveAtIndex (T & dataOut, const int & index)	const
{
	bool success = false;

	if (index <= (numValues - 1) && index > 0)
	{
		dataOut = list[index];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: retrieveFront (T & dataOut)	const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: retrieveBack (T & dataOut)	const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues - 1];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: removeFront (T & dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];

		for (int i = 0; i < (numValues - 1); i++)
		{
			list[i] = list[i + 1];
		}
		numValues--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T>:: removeAtIndex (T & dataOut, const int & index)
{
	bool success = false;

	if (index <= numValues - 1 && index > 0)
	{
		dataOut = list[index];

		for (int i = index; i < (numValues - 1); i++)
		{
			list[i] = list[i + 1];
		}
		numValues--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
void ArrList <T> :: trimToSize()
{
	T * temp = new (nothrow) T [numValues];

	if (temp != nullptr)
	{
		for (int i = 0; i < numValues; i++)
		{
			temp[i] = list[i];
		}

		delete [] list;
		list = temp;
		capacity = numValues;
	}
}

//*****************************************************************************************************

template <typename T>
void ArrList <T> :: clearList()
{
	numValues = 0;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: isEmpty()	const
{
	bool success = false;

	if (numValues > 0)
	{
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool ArrList <T> :: getBiggest (T & dataOut)	const
{
	bool success = false;
	T biggest = list[0];

	if (numValues > 0)
	{
		for (int i = 1; i < numValues; i++)
		{
			if (list[i] > biggest)
				biggest = list[i];
		}
		success = true;
		dataOut = biggest;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
int ArrList <T> :: getCapacity() const
{
	return capacity;
}

//*****************************************************************************************************

template <typename T>
int ArrList <T> :: getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template <typename T>
int ArrList <T> :: find (const T & dataIn)	const
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < numValues && !found)
	{
		if (list[index] == dataIn)
		{
			found = true;
			position = index;
		}
		index++;
	}

	return position;
}

//*****************************************************************************************************

#endif