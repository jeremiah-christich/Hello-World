//*****************************************************************************************************
//
//			File:					LinkedList.h
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
//			This program contains the linked list class and member functions
//
//			Other files required: 
//									Node.h
//									LLDriver.cpp
//
//*****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//*****************************************************************************************************

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename T>
class LinkedList
{
private:
	Node <T> * front;
public:
	LinkedList();
	~LinkedList();
	bool insert(const T & dataIn);
	bool remove(const T & dataOut);
	bool retrieve(T & dataOut)	const;
	void display()	const;
	bool viewFront(T & dataOut)	const;
	bool viewBack(T & dataOut)	const;
	bool isEmpty()	const;
	bool isFull()	const;
	bool clearList();
	int getSize()	const;
};

//*****************************************************************************************************

template <typename T>
LinkedList <T> :: LinkedList()
{
	front = nullptr;
}

//*****************************************************************************************************

template <typename T>
LinkedList <T> :: ~LinkedList()
{
	Node <T> * pTemp = front;

	while (pTemp != nullptr)
	{
		front = front->next;
		delete pTemp;
		pTemp = front;
	}
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: insert (const T & dataIn)
{
	bool success = false;
	Node <T> * pPrev = nullptr,
			 * pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node <T> * pNew = new (nothrow) Node <T> (dataIn, pAfter);
	
	if (pNew != nullptr)
	{
		if (pPrev != nullptr)
			pPrev->next = pNew;
		else
			front = pNew;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: remove (const T & dataIn)
{
	bool success = false;
	Node <T> * pPrev = nullptr,
			 *pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	if (pAfter != nullptr && pAfter->data == dataIn)
	{
		if (pPrev != nullptr)
			pPrev->next = pAfter->next;
		else
			front = pAfter->next;

		dataIn = pAfter->data;
		delete pAfter;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: retrieve (T & dataOut)	const
{
	bool success = false;
	Node <T> * pTemp = front;

	while (pTemp != nullptr && pTemp->data < dataOut)
	{
		if (pTemp->data == dataOut)
		{
			success = true;
			dataOut = pTemp->data;
		}

		pTemp = pTemp->next;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
void LinkedList <T> :: display()	const
{
	Node <T> * pTemp = front;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->next;
	}

	cout << endl;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: viewFront (T & dataOut)	const
{
	Node <T> * pTemp = front;
	bool success = false;

	if (pTemp != nullptr)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: viewBack (T & dataOut)	const
{
	Node <T> * pTemp = front;
	bool success = false;

	while (pTemp != nullptr)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: isEmpty()	const
{
	bool empty = false;

	if (front == nullptr)
		empty = true;

	return empty;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: isFull()	const
{
	bool full = false;
	Node <T> * pNew = new (nothrow) Node <T> ();

	if (pNew == nullptr)
	{
		full = true;
		delete pNew;
	}
		
	return full;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList <T> :: clearList()
{
	bool success = false;
	Node <T> * pTemp = front;

	if (front == nullptr)
	{
		success = true;
	}
	else
	{
		while (pTemp != nullptr)
		{
			front = front->next;
			delete pTemp;
			pTemp = front;
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
int LinkedList <T> :: getSize()	const
{
	int counter = 0;
	Node <T> * pTemp = front;

	while (pTemp != nullptr)
	{
		pTemp = pTemp->next;
		counter++;
	}

	return counter;
}

//*****************************************************************************************************

#endif