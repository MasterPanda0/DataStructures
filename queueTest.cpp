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
