#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int f(string str, char c) {
	if(str.size() == 1) {
		if(str[0] == c) return 0;
		return 1;
	}

	int sz = str.size();
	string leftStr = str.substr(0, sz / 2);
	string rightStr = str.substr(sz / 2);

	int leftCnt = 0;
	int rightCnt = 0;

	for(char cc : leftStr) {
		if(cc != c) leftCnt++;
	}

	for(char cc : rightStr) {
		if(cc != c) rightCnt++;
	}

	return min(leftCnt + f(rightStr, c + 1), rightCnt + f(leftStr, c + 1));
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		string str;
		cin >> str;
		printf("%d\n", f(str, 'a'));
	}
}