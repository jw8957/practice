#include <iostream>
#include <string>

using namespace std;

string str_reverse(string str) {
	if(str.size() <= 1) {
		return str;
	}
	reverse(str.begin(), str.end());
	int last = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != ' ') {
			continue;
		} else {
			reverse(str.begin() + last, str.begin() + i);
			last = i + 1;
		}
	}
	if(last < str.size()) {
		reverse(str.begin() + last, str.end());
	}

	return str;
}

int main() {
	cout << str_reverse("I love Baidu ") << endl;
	return 0;
}
