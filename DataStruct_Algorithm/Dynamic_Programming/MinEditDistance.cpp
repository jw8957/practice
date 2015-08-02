#include <iostream>
#include <string>

using namespace std;

int minOfThree(int a, int b, int c) {
	int min_val = a;
	min_val = min(min_val, b);
	min_val = min(min_val, c);

	return min_val;
}

int minEditDistance(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();

	if(!len1) {
		return len2;
	}

	if(!len2) {
		return len1;
	}

    int** D = new int*[len1 + 1];
	for(int i = 0; i < len1 + 1; i++) {
		D[i] = new int[len2 + 1];
		D[i][0] = i;
	}

	for(int j = 0; j < len2 + 1; j++) {
		D[0][j] = j;
	}

	for(int i = 1; i <= len1; i++) {
		for(int j = 1; j <= len2; j++) {
			D[i][j] = minOfThree(D[i - 1][j] + 1, D[i][j - 1] + 1, (s1[i - 1] == s2[j - 1]) ? D[i - 1][j - 1]: D[i - 1][j - 1] + 1);
		}
	}
	
	int res = D[len1][len2];
	delete [] D;
	return res;
}

void unit_test(string s1, string s2) {
	cout << s1 << endl;
	cout << s2 << endl;
	cout << minEditDistance(s1, s2) << endl;
	cout << "========================" << endl;
}

int main() {
	unit_test("abc", "abd");
	unit_test("", "abd");
	unit_test("aewf", "kilsd");
	unit_test("alopd", "lope");

    return 0;
}
