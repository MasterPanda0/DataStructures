/**
 *  Filename  : doubleLinkedList.cpp
 *  Language  : C/C++11
 *  Author    : Hubertus Hans (hubertus.hans@imatek.tech)
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
