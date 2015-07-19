/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and
 * ignoring cases. 
 **/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSame(char s1, char s2) {
        int diff = 'A' - 'a';
        if(s1 >= 'A' && s1 <= 'Z') {
            s1 = s1 - diff;
        }
        if(s2 >= 'A' && s2 <= 'Z') {
            s2 = s2 - diff;
        }
        cout << s1 << " " << s2 << endl;
        return (s1 == s2);
    }
    
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            while(!isAlphanumeric(s[left]) && (left < right)) {
                left++;
            }
            while(!isAlphanumeric(s[right]) && (right > left)) {
                right--;
            }
            if((left < right) && !(isSame(s[left], s[right]))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


int main() {
    Solution s;
    cout << s.isPalindrome("ab") << endl;
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
