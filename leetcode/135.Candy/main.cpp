#include "../include.h"

class Node {
public:
	Node(int _idx, int _value) {
		idx = _idx;
		value = _value;
	}
	int idx;
	int value;
};

class Compare {
public:
	bool operator() (Node n1, Node n2) {
		return n1.value > n2.value;
	}
};

class Solution {
public:
	int candy(vector<int>& ratings) {
		int size = ratings.size();
		if(!size) {
			return 0;
		}
		
		vector<int> candiesArr(size, 1);
		int res = 0;
		
		vector<Node> nodeArr;
		for(int i = 0; i < size; i++) {
			Node n_tmp(i, ratings[i]);
			nodeArr.push_back(n_tmp);
		}
		
		priority_queue<Node, vector<Node>, Compare> nodeQueue(nodeArr.begin(), nodeArr.end());
		while(!nodeQueue.empty()) {
			Node n_tmp = nodeQueue.top();
			nodeQueue.pop();
			int idx = n_tmp.idx;
			if(idx == 0) {
				if((ratings[idx] > ratings[idx + 1]) && (candiesArr[idx] <= candiesArr[idx + 1])) {
					candiesArr[idx] = candiesArr[idx + 1] + 1;
				}
			} else if(idx == size - 1) {
				if((ratings[idx] > ratings[idx - 1]) && (candiesArr[idx] <= candiesArr[idx - 1])) {
					candiesArr[idx] = candiesArr[idx - 1] + 1;
				}
			} else {
				if((ratings[idx] > ratings[idx + 1]) && (candiesArr[idx] <= candiesArr[idx + 1])) {
					candiesArr[idx] = candiesArr[idx + 1] + 1;
				}
				if((ratings[idx] > ratings[idx - 1]) && (candiesArr[idx] <= candiesArr[idx - 1])) {
					candiesArr[idx] = candiesArr[idx - 1] + 1;
				}
			}

			res += candiesArr[idx];
		}

		//for(int i = 0; i < size; i ++) {
		//	cout << candiesArr[i];
		//}
		//cout << endl;
		return res;
	}
};


int main() {
	Solution s;
	int arr[] = {2, 5, 4, 1, 3};
	vector<int> n_arr(arr, arr + sizeof(arr) / sizeof(int));
	s.candy(n_arr);
	return 0;
}
