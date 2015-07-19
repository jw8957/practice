/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
#include <iostream>
#include <vector>

using namespace std;

void Permutation(vector<int> arr, int erase_idx, vector<int> got) {
    if(erase_idx >= 0 && erase_idx < arr.size()) {
		vector<int>::iterator e = arr.begin() + erase_idx;
        arr.erase(e);
    }

    if(arr.size() == 0) {
        for(vector<int>::iterator it = got.begin(); it != got.end(); it++) {
            cout << *it;
        }
        cout << endl;
        return;
    }
    
    for(int i = 0; i < arr.size(); i++) {
        vector<int> got_n(got);
		got_n.push_back(arr[i]);
        Permutation(arr, i, got_n);
    }
}


int main() {
    int tmp_init[] = {1};
    vector<int> arr(tmp_init, tmp_init + sizeof(tmp_init)/sizeof(int));

    vector<int> a;
    Permutation(arr, -1, a);

    return 0;
}
