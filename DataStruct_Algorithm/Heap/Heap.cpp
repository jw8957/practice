/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file Heap.cpp
 * @author jiwei03(com@baidu.com)
 * @date 2015/05/26 10:28:50
 * @brief 
*/

#include <iostream>
using namespace std;


class Heap {
public:
	int Max_size;
	int size;
	
	Heap(int max_size = 100) {
		this->Max_size = max_size;
		this->arr = new int[this->Max_size];
	}

	~Heap() {
		delete this->arr;
	}

	int BuildHeap(int* arr_i, int len) {
		if(len >= this->Max_size) {
			return 1;
		}

		memcpy(this->arr, arr_i, sizeof(int) * len);
		size = len;

		for(int i=0; i< this->size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;

		for(int i = (size - 2) / 2; i >= 0; i--) {
			this->Max_Heapify(i);
		}
		return 0;
	}

	int HeapSort() {
		int size = this->size;
		while(this->size > 0) {
			this->swap(0, this->size - 1);
			this->size--;
			this->Max_Heapify(0);
		}
		for(int i=0; i < size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}

	void printHeap() {
		for(int i=0; i< this->size; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}

private:
	int* arr;

	int left(int idx) {
		return 2 * idx + 1;
	}

	int right(int idx) {
		return 2 * idx + 2;
	}

	int parent(int idx) {
		return (idx - 1) / 2;
	}

	void swap(int idx1, int idx2) {
		int tmp = this->arr[idx1];
		this->arr[idx1] = this->arr[idx2];
		this->arr[idx2] = tmp;
	}

	void Max_Heapify(int idx) {
		if(!(idx >= 0 && idx < size)) {
			return;
		}
		
		int left_idx = left(idx);
		int right_idx = right(idx);
		int max_idx = idx;

		if(left_idx < size && this->arr[left_idx] > this->arr[max_idx]) {
			max_idx = left_idx;
		}
		
		if(right_idx < size && this->arr[right_idx] > this->arr[max_idx]) {
			max_idx = right_idx;
		}

		if(max_idx != idx) {
			this->swap(max_idx, idx);
			this->Max_Heapify(max_idx);
		}
	}
};

int main() {
	Heap h(50);
	int len = 10;
	int a[10] = {5,1,9,2,3,4,10,23,4,16};

	h.BuildHeap(a, len);
	h.printHeap();
	h.HeapSort();

	return 0;
}
