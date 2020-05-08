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
 *  Filename  : BinaryTree1.cpp
 *  Language  : C/C++11
 */
 
 #include <iostream>
#include <string>
#include <sstream>  
using namespace std;

struct node {
	int data;
	node* parent;
	node* left;
	node* right;
}*root=NULL;

string center(string msg, int len, char spacer = ' ') {  //padding string center
	int sl = len - msg.length(); //menentukan space yang perlu diisi
	string hasil = "";
	if (sl % 2 != 0) hasil += spacer;
	for (int i = 0; i < sl / 2; i++)hasil += spacer;
	hasil += msg;
	for (int i = 0; i < sl / 2; i++)hasil += spacer;
	return hasil;
}

string memCenter(node *ptr, int len, char spacer = ' ') { //padding mem addr to centered string
	if (ptr == NULL)return center("-1", len, spacer);
	stringstream ss;
	ss << ptr;
	return center(ss.str(), len, spacer);
}

node* maximumVal(node* ptr) //node maksimum dlm suatu subtree
{
	while (ptr->right != NULL) {
		ptr = ptr->right;
	}
	return ptr;
}

void insert(int x, node* ptr = root) {
	node* newNode = new node;
	newNode->data = x;
	newNode->left = newNode->right= newNode->parent = NULL;
	if (root == NULL) root = newNode;
	else {
		if (ptr->data > x) {
			if (ptr->left == NULL) {
				ptr->left = newNode;
				newNode->parent = ptr;
			}
			else return insert(x, ptr->left);
		}
		else {
			if (ptr->right == NULL) {
				ptr->right = newNode;
				newNode->parent = ptr;
			}
			else return insert(x, ptr->right);
		}
	}
}

void deleteNode(int x, node* ptr=root)
{
	if (x < ptr->data) deleteNode(x,ptr->left);
	else if (x > ptr->data) deleteNode(x, ptr->right);
	else
	{
		if (ptr->left == NULL && ptr->right == NULL) //leaf
		{
			if (ptr == ptr->parent->left)ptr->parent->left = NULL;
			else ptr->parent->right = NULL;
			free(ptr);
		}else if (ptr->left && ptr->right) //tengah
		{
			node* max = maximumVal(ptr->left);
			ptr->data = max->data;
			deleteNode(max->data,ptr->left);
		}else //pincang
		{
			node* child = (ptr->left) ? ptr->left : ptr->right;
			if (ptr == ptr->parent->left)ptr->parent->left = child;
			else ptr->parent->right = child;
			free(ptr);
		}
	}
}

void print(node* ptr) {
	if (ptr != NULL) {
		cout <<"|"<< memCenter(ptr,15) << "|"<<memCenter(ptr->left, 15)<<"|"<<center(to_string(ptr->data),10);
		cout << "|" << memCenter(ptr->right, 15) << "|" << endl;
		print(ptr->left);
		print(ptr->right);
	}
}

void printAll() {
	if (root == NULL)cout << "Tree not found / Empty!" << endl;
	else {
		cout << "------------------------------------------------------------" << endl;
		cout << "|" + center("MEM ADDR", 15) + "|" + center("*LEFT", 15) + "|" + center("DATA", 10) + "|" + center("*RIGHT", 15) + "|" << endl;
		cout << "------------------------------------------------------------" << endl;
		print(root);
		cout << "------------------------------------------------------------" << endl << endl;
	}
}

int main()
{
	insert(4);
	insert(2);
	insert(7);
	insert(1);
	insert(3);
	insert(6);
	insert(8);
	cout << "Original Tree:" << endl;
	printAll();
	insert(5);
	cout << "Insert(5): " << endl;
	printAll();
	deleteNode(7);
	cout << "Delete(7): " << endl;
	printAll();
}
