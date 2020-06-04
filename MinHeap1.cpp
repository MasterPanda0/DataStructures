/**
 *  Copyright (C) 2020 by Hubertus Hans (Hubertus.Hans@imatek.tech)
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
 *  to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 *  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *  Filename  : MinHeap1.cpp
 *  Language  : C/C++11
 */
 
#include <iostream>
#include <string>
using namespace std;

int HEAP[100000], N=0;

void init() {
	N = 1;
	HEAP[0] = -1;
}

void insert(int val) {
	int PAR, temp;
	HEAP[N] = val;
	N++;
	int POS = N-1;
	while (POS > 0) {
		PAR = POS / 2;
		if (HEAP[PAR] <= HEAP[POS]) return;
		temp = HEAP[POS];
		HEAP[POS] = HEAP[PAR];
		HEAP[PAR] = temp;
		POS = PAR;
	}
}


int main()
{
	init();
	int val=0;
	int Nilai;
	while (true) {
		cout << "Input nilai node: ";
		cin >> val;
		if (val == -1)break;
		insert(val);
	}
	for (int i = 0; i < N; i++) {
		Nilai = HEAP[i];
		cout << "Hasil= " << Nilai << endl;
	}
}
