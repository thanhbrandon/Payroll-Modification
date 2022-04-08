#ifndef PAYLIST_H
#define PAYLIST_H
#include <iostream>

using namespace std;

class PayList
{
private:
	// Declare a structure for the list
	struct PayNode
	{
		int emID;
		int hours;
		double payRate;

		struct PayNode* next; // To point to the next node
	};

	PayNode* head; // List Head pointer

public:
	// Constructor
	PayList() {
		head = nullptr;
	}

	// Destructor
	~PayList();

	// Linked list operations
	void appendNode(int, double);
	void displayList() const;
};

PayList::~PayList()
{
	PayNode* current = head;
	while (current != 0) {
		PayNode* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

void PayList::appendNode(int newEmID, double newPayRate)
{
	PayNode* newNode; // To point to a new node 
	PayNode* nodePtr; // To move through the list

	// Allocate a new node and store num there
	newNode = new PayNode;
	newNode->emID = newEmID;
	newNode->payRate = newPayRate;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}
void PayList::displayList() const {
	PayNode* nodePtr; // To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// Set up the numeric output formatting.
	cout << fixed << showpoint << setprecision(2) << endl;

	// Display the header.
	cout << "----------------------------\n";
	cout << "Employee               Wages\n";
	cout << "----------------------------\n\n";


	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display each employee's pay.
		cout << "Employee #" << nodePtr->emID << "   $";
		cout << setw(7) << nodePtr->payRate << endl << endl;
		// Move to the next node
		nodePtr = nodePtr->next;
	}
}


#endif
#pragma once
