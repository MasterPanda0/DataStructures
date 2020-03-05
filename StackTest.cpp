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
 *  Filename  : StackTest.cpp
 *  Language  : C/C++11
 */

#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class node {
public:
	int val;
	node* next;
};


class Stack {
private:
	node* head = NULL;
	node* tail = NULL;
	struct node *newNode, *ptr;

public:
	void push(int x) {
		newNode = (node*)malloc(sizeof(node));
		(*newNode).val = x;
		(*newNode).next = NULL;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			ptr = head;
			while ((*ptr).next != NULL)
			{
				ptr = (*ptr).next;
			}
			(*ptr).next = newNode;
			tail = newNode;
			(*newNode).next = NULL;
		}
	}
	int top() {
		return tail->val;
	}
	void pop() {
		if (head != NULL && tail != NULL){
			ptr = head;
			while ((*ptr).next != tail) {
				ptr = (*ptr).next;
			}
			delete(tail);
			ptr->next = NULL;
			tail = ptr;
		}
	}
	void printAll() {
		node* teuing = head;
		while (teuing->next != tail->next) {
			cout << teuing->val << "::";
			teuing = teuing->next;
		}
		cout << teuing->val << endl;
	}

};

int main()
{
	Stack stacks;
	stacks.push(10);
	stacks.push(12);
	stacks.push(15);
	stacks.push(22);
	cout << "Stack utuh: ";
	stacks.printAll();
	cout<<"top: "<<stacks.top()<<endl;
	cout << "POP();" << endl;
	stacks.pop();
	stacks.printAll();
	return 0;
}
