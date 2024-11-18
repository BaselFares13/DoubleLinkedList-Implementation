#include "DoubleLinkedlist.h"
#include <iostream>

using namespace std;

bool DoubleLinkedlist::isFound(int x) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == x) {
			return 1;
		}

		temp = temp->next;
	}

	return 0;
}


bool DoubleLinkedlist::isEmpty() {
	return head == NULL;
}


void DoubleLinkedlist::add_beg(int x) {
	Node* newnode = new Node;
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = head;

	if (head == NULL)
		tail = newnode;
	else
		head->prev = newnode;

	head = newnode;
	length++;
}


void DoubleLinkedlist::add_end(int x) {
	Node* newnode = new Node;
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = tail;

	if (tail == NULL)
		head = newnode;
	else
		tail->next = newnode;

	tail = newnode;
	length++;
}


void DoubleLinkedlist::add_after(int item, int x) {
	if (isFound(item)) {
		if (tail->data == item) {
			add_end(x);
		}
		else {
			Node* newnode = new Node;
			newnode->data = x;
			Node* temp = head;
			while (temp->data != item)
				temp = temp->next;
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next->prev = newnode;
			temp->next = newnode;

			length++;
		}
	}
	else {
		cout << "The item is not existing !!" << endl;
	}
}


void DoubleLinkedlist::add_before(int item, int x) {
	if (isFound(item)) {
		if (head->data == item) {
			add_beg(x);
		}
		else {
			Node* newnode = new Node;
			newnode->data = x;
			Node* temp = head;
			while (temp->data != item)
				temp = temp->next;
			newnode->next = temp;
			newnode->prev = temp->prev;
			temp->prev->next = newnode;
			temp->prev = newnode;

			length++;
		}
	}
	else {
		cout << "The item is not existing !!" << endl;
	}
}


void DoubleLinkedlist::delete_beg() {
	if (isEmpty()) {
		cout << "The list is already empty !!" << endl;
	}
	else {
		Node* temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		delete temp;

		length--;
	}
}


void DoubleLinkedlist::delete_end() {
	if (isEmpty()) {
		cout << "The list is already empty !!" << endl;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;
		delete temp;

		length--;
	}
}


void DoubleLinkedlist::delete_at(int x) {
	if (isFound(x)) {
		if (head->next == NULL)
			delete_beg();
		else if (head->data == x)
			delete_beg();
		else if (tail->data == x)
			delete_end();
		else {
			Node* temp = head;
			while (temp->data != x)
				temp = temp->next;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;

			length--;
		}
	}
	else {
		cout << "The item is not existing !!" << endl;
	}
}


void DoubleLinkedlist::print() {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}


void DoubleLinkedlist::rprint() {
	Node* temp = tail;

	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->prev;
	}
}


