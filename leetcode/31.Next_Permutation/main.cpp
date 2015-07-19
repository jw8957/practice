#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nextMinIdx(vector<int> nums, int idx) {
    if(idx == nums.size() - 1) {
        return idx;
    }
    int min_idx = idx;
    int min_element = nums[idx];

    for(int i = idx; i < nums.size(); i++) {
        if(nums[idx] == min_element && nums[i] > nums[idx]) {
            min_idx = i;
            min_element = nums[i];
        } else if(nums[i] > nums[idx] && nums[i] < min_element) {
            min_idx = i;
            min_element = nums[i];
        }
    }
	cout << "min idx:" << min_idx << endl;
    return min_idx;
}

void next_permutation(vector<int> & nums) {
    int size = nums.size();
    if(size < 2) {
        return;
    }

    for(int i = size - 1; i >= 0; i--) {
        int next_min_idx = nextMinIdx(nums, i);
        if(next_min_idx == i) {
            continue;
        }
        swap(nums[i], nums[next_min_idx]);
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
    reverse(nums.begin(), nums.end());
}

int main() {
    int a[] = {1,1,5};
    vector<int> arr(a, a + sizeof(a)/sizeof(int));
    next_permutation(arr);
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it;
    }
    cout << endl;
    return 0;
}
