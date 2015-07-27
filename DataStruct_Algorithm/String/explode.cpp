#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> explode(string origin, string delimiter) {
	vector<string> res;
	int len1 = origin.size();
	int len2 = delimiter.size();
	if(len1 == 0 || len2 == 0) {
		return res;
	}
	
	if(len1 < len2) {
		return res;
	}
	
	int last_pos = 0;
	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2 && (i + j) < len1; j++) {
			if(origin[i + j] == delimiter[j]) {
				if(j == len2 - 1) {
					string seg(origin, last_pos, i - last_pos);
					res.push_back(seg);
					last_pos = i + j + 1;
				} else {
					continue;
				}
			} else {
				break;
			}
		}
	}
	if(last_pos >= len1) {
		res.push_back("");
	} else {
		string seg(origin, last_pos, len1 - last_pos);
		res.push_back(seg);
	}
	return res;
}

void unittest(string str1, string str2) {
	vector<string> s = explode(str1, str2);
	cout << str1 << ":" << str2 << endl;
	for(int i = 0; i < s.size(); i++) {
		cout << s[i] << "|" ;
	}
	cout << endl << "====================================================" << endl;
}

int main() {
	unittest("abcd", "bc");
	unittest("def", "bc");
	unittest("Today is Monday ", " ");

	return 0;
}
