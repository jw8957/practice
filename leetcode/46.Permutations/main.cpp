/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void Permutation(vector<int> arr, int cur_idx, vector<int> perm, vector<vector<int> >& res) {
    if(cur_idx == arr.size() - 1) {
        perm[cur_idx] = arr[cur_idx];
        res.push_back(perm);
        return;
    }

	set<int> dupli;
    for(int i = cur_idx; i < arr.size(); i++) {
        ////if((i > cur_idx) && (arr[i] == arr[cur_idx])) {
        ////    continue;
        ////}
		if(dupli.find(arr[i]) != dupli.end()) {
			continue;
		} else {
			dupli.insert(arr[i]);
		}

        swap(arr[cur_idx], arr[i]);
        perm[cur_idx] = arr[cur_idx];
        Permutation(arr, cur_idx + 1, perm, res);
        swap(arr[cur_idx], arr[i]);
    }
}

int main() {
    int a[] = {1, 2, 3};
    //int a[] = {3, 3, 3};
	vector<int> arr(a, a + sizeof(a)/sizeof(int));
	vector<int> perm(arr);
	vector<vector<int> > res;

	Permutation(arr, 0, perm, res);

	for(vector<vector<int> >::iterator it1 = res.begin(); it1 != res.end(); it1++) {
		for(vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
			cout << *it2;
		}
		cout << endl;
	}

    return 0;
}


