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
 *  Filename  : deleteAll_InsertAfter.cpp
 *  Language  : C/C++11
 */
 

#include <iostream>
#include<stdlib.h>

using namespace std;

struct tnode {
	int value;
	tnode* next;
};

tnode* head = NULL;

void hapus(int x) {
	int count = 0;
	tnode* tmp = head;
	while (tmp != NULL) {
		if (tmp->value == x)count++;
		tmp = tmp->next;
	}
	for (int i = 0; i < count; i++) {
		tmp = head;
		if (head->value == x) {
			head = head->next;
			free(tmp);
		}
		else {
			tnode* ptr;
			while (tmp->next->value != x) {
				tmp = tmp->next;
			}
			if (tmp->next != NULL) {
				tnode* buff = tmp->next;
				tmp->next = buff->next;
				free(buff);
			}
			else {
				free(tmp->next);
				tmp->next = NULL;
			}
		}
	}
}
void printAll() {
	tnode* ptr = head;
	while (ptr->next != NULL) {
		cout << ptr->value << "->";
		ptr = ptr->next;
	}
	cout << ptr->value << endl;
}

void insertAfter(int x, int y) {
	tnode* nN = new tnode;
	nN->value = y;
	if (head == NULL) {
		nN->next = NULL;
		head = nN;
	}
	else {
		if (head->value == x) {
			nN->next = head->next;
			head->next = nN;
		}
		else {
			tnode* ptr = head;
			while (ptr->next->value != x)ptr = ptr->next;
			nN->next = ptr->next->next;
			ptr->next->next = nN;
		}
	}
}

int main() {
	tnode* node = (tnode*)malloc(sizeof(tnode));
	node->value = 12;
	node->next = NULL;
	head = node;

	tnode* node1 = (tnode*)malloc(sizeof(tnode));
	node1->value = 13;
	node1->next = NULL;
	node->next = node1;

	int n;
	cout << "Masukan nilai: ";
	cin >> n;
	while (n != -1) {
		tnode* nNode = new tnode;
		nNode->value = n;
		if (head == 0) {
			head = nNode;
			nNode->next = NULL;
		}
		else {
			nNode->next = head;
			head = nNode;
		}
		cout << "Masukan nilai: ";
		cin >> n;
	}
  
	printAll();

	cout << "MASUKAN SETELAH!!!" << endl;
	cout << "Masukan nilai: ";
	cin >> n;
	while (n != -1) {
		int teuing;
		cout << "Setelah: ";
		cin >> teuing;
		insertAfter(teuing, n);
		printAll();
		cout << "Masukan nilai: ";
		cin >> n;
	}
	printAll();

	cout << "Masukan nilai untuk dihapus: ";
	cin >> n;
	while (n != -1) {
		hapus(n);
		printAll();
		cout << "Masukan nilai untuk dihapus: ";
		cin >> n;
	}
  return 0;
}
