#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findKthNum(vector<int> arr1, vector<int> arr2, int K) {
			if(arr1.size() > arr2.size()) {
				return findKthNum(arr2, arr1, K);
			}
	
			if(arr1.size() == 0) {
				return arr2[K - 1];
			} 
			
			if(K == 1) {
				return min(arr1[0], arr2[0]);
			}

            int k1 = min(K/2, (int)arr1.size());
            int k2 = K - k1;

            if(arr1[k1 - 1] == arr2[k2 - 1]) {
                return arr1[k1 - 1];
            } else if(arr1[k1 - 1] < arr2[k2 - 1]) {
                vector<int> subarr(arr1.begin() + k1, arr1.end());
                return findKthNum(subarr, arr2, k2);
            } else {
                vector<int> subarr(arr2.begin() + k2, arr2.end());
                return findKthNum(arr1, subarr, k1);
            }
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int size1 = nums1.size();
			int size2 = nums2.size();
			if((size1 + size2) % 2 == 1) {
				return findKthNum(nums1, nums2, (size1 + size2) / 2 + 1);
			} else {
				return (findKthNum(nums1, nums2, (size1 + size2) / 2) + findKthNum(nums1, nums2, (size1 + size2) / 2 + 1)) / 2;
			}
            return 0;
        }
};


int main() {
	int arr1[] = {};
	int arr2[] = {1};
	vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
	vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));

	Solution s;
	cout << s.findMedianSortedArrays(v1, v2) << endl;
    return 0;
}
