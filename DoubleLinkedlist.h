#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>

using namespace std;


struct Node {
	int data;
	Node* next;
	Node* prev;
};


class DoubleLinkedlist {
private:
	Node* head = NULL;
	Node* tail = NULL;

public:
	int length = 0;

	bool isFound(int x);

	bool isEmpty();

	void add_beg(int x);

	void add_end(int x);

	void add_after(int item, int x);

	void add_before(int item, int x);

	void delete_beg();

	void delete_end();

	void delete_at(int x);

	void print();

	void rprint();
};


#endif // !DOUBLELINKEDLIST_H
