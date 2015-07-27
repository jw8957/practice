#include <iostream>
using namespace std;

char* strstr(const char* str1, const char* str2) {
	if(!str1 || !str2) {
		return NULL;
	}
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if(len1 < len2) {
		return NULL;
	}

	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2 && (i + j) < len1; j++) {
			if(str1[i + j] == str2[j]) {
				if(j == len2 - 1) {
					return (char*)str1 + i;
				} else {
					continue;
				}
			} else {
				break;
			}
		}
	}
	return NULL;
}

void unittest(const char* str1, const char* str2) {
	char* s = strstr(str1, str2);
	if(!s) {
		cout << "NULL" << endl;
	} else {
		cout << s << endl;
	}
}

int main() {
	unittest("abcd", "bc");
	unittest("def", "bc");

	return 0;
}
