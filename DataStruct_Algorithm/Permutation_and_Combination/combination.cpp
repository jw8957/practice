/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void getCombination(const vector<int>& arr, int cur, vector<int> got_arr, int size, vector<vector<int> >& res) {
    if(got_arr.size() == size) {
        res.push_back(got_arr);
        return;
    }
    if(cur >= arr.size()) {
        return;
    }
    
    if(arr.size() - cur >= size - got_arr.size()) {
        getCombination(arr, cur + 1, got_arr, size, res);
        got_arr.push_back(arr[cur]);
        getCombination(arr, cur + 1, got_arr, size, res);
    }
}

int main() {
    vector<vector<int> > res;

    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

    for(int i = 1; i <= v.size(); i++) {
        vector<int> tmp;
        getCombination(v, 0, tmp, i, res);
    }

    vector<vector<int> >::iterator it1;
    for(it1 = res.begin(); it1 != res.end(); it1++) {
        vector<int>::iterator it2;
        for(it2 = it1->begin(); it2 != it1->end(); it2++) {
            cout << *it2;
        }
        cout << endl;
    }
    
    return 0;
}
