/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
#include <iostream>
using namespace std;

int max(int left, int right) {
    return (left > right) ? left : right;
}

int knapsack(int* wei_arr, int* cap_arr, int num, int V) {
    int** F = new int*[num + 1];
	for(int i = 0; i <= V; i++) {
		F[i] = new int[V + 1];
	}
    for(int i = 0; i <= V; i++) {
        F[0][i] = 0;
    }

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= V; j++) {
            if(j < cap_arr[i - 1]) {
                F[i][j] = F[i - 1][j]; 
            } else {
                F[i][j] = max(F[i - 1][j], F[i - 1][j - cap_arr[i - 1]] + wei_arr[i - 1]);
            }
        }
    }
    int res = F[num][V];
    //delete []F;
    return res;
}

int main() {
    int V = 5;
    int num = 4;
    int wei_arr[] = {3, 5, 4, 6};
    int cap_arr[] = {2, 3, 1, 3};

    cout << knapsack(wei_arr, cap_arr, num, V) << endl;

    return 0;
}
