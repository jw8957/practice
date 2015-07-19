/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 1_two_sum.cpp
 * @author jiwei03(com@baidu.com)
 * @date 2015/05/19 23:33:32
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> save;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator it;
            it = save.find(target - nums[i]);
            if(it == save.end()) {
                save[nums[i]] = i + 1;
            } else {
                res.push_back(save[target - nums[i]]);
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> a;
    a.push_back(3);
    a.push_back(2);
    a.push_back(4);

    Solution* s = new Solution();
    vector<int> res;
    res = s->twoSum(a, 6);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
