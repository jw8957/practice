#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string origin, string delimiter) {
	vector<string> res;
	int len1 = origin.size();
	int len2 = delimiter.size();
	if(len1 == 0 || len2 == 0) {
		return res;
	}
	
	if(len1 < len2) {
		res.push_back(origin);
		return res;
	}
	
	int last_pos = 0;
	int i = 0;
	while(i <= len1 - len2) {
		if(origin.compare(i, len2, delimiter) == 0) {
			string seg(origin, last_pos, i - last_pos);
			res.push_back(seg);
			last_pos = i + len2;
			i += len2;
		} else {
			i++;
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
	vector<string> s = split(str1, str2);
	cout << "[" << str1 << "] split by [" << str2 << "]" << endl;
	for(int i = 0; i < s.size(); i++) {
		cout << s[i] << "|" ;
	}
	cout << endl << "====================================================" << endl;
}

int main() {
	unittest("abcd", "bc");
	unittest("def", "bc");
	unittest("Today is Monday ", " ");
	unittest("Today is Monday", "	");

	return 0;
}
