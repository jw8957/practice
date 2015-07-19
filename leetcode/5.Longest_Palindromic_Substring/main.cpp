/***************************************************************************
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 **************************************************************************/
 
 
 
/**
 * @file main.cpp
 * @author jiwei03(com@baidu.com)
 * @date 2015/06/08 23:52:32
 * @brief 
 *  
 **/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s, int left, int right) {
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


string longestPalindrome(string s) {
    int longest = 0;
    string res;

    map<char, vector<int> > cap;

    for(int i = 0; i < s.size(); i++) {
        char cur = s[i];
        if(cap.find(cur) == cap.end()) {
            vector<int> tmp;
            tmp.push_back(i);
            cap[cur] = tmp;
        } else {
            vector<int>& tmp2 = cap[cur];
            for(int j = 0; j < tmp2.size(); j++) {
                int left = tmp2[j];
                int right = i;
                if((right - left + 1) < longest) {
                    break;
                }

                if(isPalindrome(s, left, right)) {
                    longest = right - left + 1;
                    res = s.substr(left, longest);
                    break;
                }
            }
            tmp2.push_back(i);
        }
    }
    return res;
}

int main() {
    string a,b;
    a = "abdbcecbf";
    b = longestPalindrome(a);
    cout << b << endl;
    a = "a";
    b = longestPalindrome(a);
    cout << b << endl;
    a = "abadd";
    b = longestPalindrome(a);
    cout << b << endl;
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
