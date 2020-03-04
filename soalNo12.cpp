/**
 *  Copyright (C) 2020 by Hubertus Hans (Hubertus.Hans@imatek.tech)
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
 *  to deal in the Software without restriction, including without l> imitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 *  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *  Filename  : soalNo12.cpp
 *  Language  : C/C++11
 *  Soal: Make the menu and do the operation as described by using Single Linked List!
 *        1. Add Data
 *        2. See Data (Sorted Ascending)
 *        3. Exit
 *
 *        Add Data
 *
 *        Value = (insert number 1-50)
 *      
 *        See Data
 *        1->2->4
 *
 *        Value = 3
 *        1->2->3->4
 *
 */
 
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct node {
	int val;
	node* next;
};

node* head = NULL;
node* ptr;

void printAll() {
	ptr = head;
	while (ptr->next != NULL) {
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << ptr->val << endl;
}

void insert(int val) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;
	}
	else {
		if (val < head->val) {
			newNode->next = head;
			head = newNode;
		}
		else {
			ptr = head;
			while (ptr->next != NULL && ptr->next->val < val) {
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
}

int main() {
	int p = 0;
	while (p != 3) {
		cout << "Menu:" << endl;
		cout << "1. Add data \n2. See data (Sorted Ascending) \n3. Exit \nPilihan: ";
		cin >> p;
		if (p == 1) {
			int val;
			cout << "Insert number (1-50) : ";
			cin >> val;
			insert(val);
		}
		else if (p == 2) {
			printAll();
		}
		cout << endl;
	}
}
