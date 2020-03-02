/**
 *  Copyright (C) 2020 by Hubertus Hans
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
 *  Filename  : doubleLinkedList.cpp
 *  Language  : C/C++11
 *  Email     : hubertus.hans@imatek.tech
 *  Year      : 2020
 *
 */
 
 
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct dlNode {
	int val;
	dlNode* next;
	dlNode* prev;
};

dlNode* head = NULL;

void insertFront(int val) {
	dlNode *newNode;
	newNode = (dlNode*)malloc(sizeof(dlNode));
	newNode->val = val;
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}
}

void insertMiddle(int val) {
	dlNode *newNode, *ptr, *tmp;
	newNode = (dlNode*)malloc(sizeof(dlNode));
	newNode->val = val;
	ptr = head;
	while (ptr->next->next != NULL && ptr->next->val < val) {
		ptr = ptr->next;
	}
	tmp = ptr->next;
  newNode->prev = ptr;
	newNode->next = tmp;
	ptr->next = newNode;
	tmp->prev = newNode;
}

void insertBack(int val) {
	dlNode *newNode, *ptr;
	newNode = (dlNode*)malloc(sizeof(dlNode));
	newNode->val = val;
	ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
	newNode->prev = ptr;
	newNode->next = NULL;
}

void printKabeh() {
	dlNode* teuing = head;
	while (teuing->next != NULL) {
		cout << teuing->val << "::";
		teuing = teuing->next;
	}
	cout << teuing->val << endl;
}

int main() {
	insertFront(55);
	insertFront(20);
	printKabeh();
	insertMiddle(40);
	insertMiddle(30);
	printKabeh();
	insertBack(5);
	insertBack(10);
	printKabeh();
}
