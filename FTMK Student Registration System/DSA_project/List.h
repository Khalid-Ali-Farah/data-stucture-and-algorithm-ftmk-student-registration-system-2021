#pragma once

#ifndef LIST_H
#define LIST_H

#include<fstream>
#include <string>
using namespace std;

// input and output file


class List
{
private:
	struct student
	{ //variables for students data
		int bil;
		string name;
		string id;
		int age;
		string grade;
	};

	//class for node 
	class Node
	{
	public:
		student studentData;
		Node* link;
	};

	//the calss pointers
	Node* pHead;// to point first node
	Node* pCurr; // current
	Node* pPrev; // Previous  pointer to Reverse a linked list
	Node* pTail;// to point last node


	int noItem; // Variavle for number of item exist in the list

public:

	// The methods

	List(); //constractor

	~List(); //deconstractor

	void InsertToFront();

	void InsertToFrontInput(int, string, string, int, string);

	void deleteFront();

	void InsertToMiddle();

	void InsertToMiddleInput(int, string, string, int, string);

	void deleteMiddle();

	int NumberOfItem();

	bool removeSearch(string, int&);

	bool searchStudentBy_ID(string, int&);

	void printSearch(int);

	void sortBy_ID();

	bool Traverse();

	void displayData();


	void clearList();

	void update();

};



#endif

