//*****************************************************************************************************
//
//		File:			    Node.h
//		
//		Student:			Jeremiah Christich
//
//		Course Name:		Data Structures II  
//
//		Course Number:		COSC 3100 - 11
//
//		Due:			    April 16, 2019 
//
//
//		This program provides the structured data type Node.
//
//		Other files required:
//                       N/A
//		
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
	T data;
	Node <T> * next;
	Node();
	Node(const T &, Node <T> * = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node <T> ::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node <T> ::Node(const T & dataIn, Node <T> * n)
{
	data = dataIn;
	next = n;
}

//*****************************************************************************************************

#endif