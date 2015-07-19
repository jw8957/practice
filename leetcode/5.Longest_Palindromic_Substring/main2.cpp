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

string Palindrome(string s, int start, int end) {
    string res;
    int s_len = s.size();
    bool isPalin = false;
    while((start >=0 ) && (end < s_len)) {
        if(s[start] != s[end]) {
            //isPalin = false;
            break;
        } else {
            isPalin = true;
            start--;
            end++;
        }
    }
    if(isPalin) {
        res = s.substr(start + 1, end - start - 1);
        //cout << res << endl;
    }
    return res;
}


string longestPalindrome(string s) {
    int longest = 0;
    string res = "";
    
    int s_len = s.size();
    for(double i = 0.5; i < s_len - 1; i += 0.5) {
        int start = int(i - 0.5);
        int end = int(i + 1);
        string tmp_pali = Palindrome(s, start, end);
        if(tmp_pali.size() > longest) {
            longest = res.size();
            res = tmp_pali;
        }
    }
    return res;
}

int main() {
    string a,b;
    a = "abdbcecbf";
    b = longestPalindrome(a);
    cout << b << endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
