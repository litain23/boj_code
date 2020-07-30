#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int f(string str, int x, int y) {
	int cnt = 0;
	bool toggle = false;

	for(char c : str) {
		if(!toggle) {
			if(c == '0' + x) {
				cnt++;
				toggle = !toggle;
			}
		} else {
			if(c == '0' + y) {
				cnt++;
				toggle = !toggle;
			}
		}
	}
	if(cnt % 2) cnt--;
	return cnt;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		cin >> str;

		int ans = 0;
		for(int i=0;i<=9;i++) {
			int cnt = 0;
			for(char c : str) {
				if(c == '0' + i) {
					cnt++;
				}
			}
			ans = max(ans, cnt);	
		}

		for(int i=0;i<=9;i++) {
			for(int j=0;j<=9;j++) {
				if(i == j) continue;
				ans = max(ans, f(str, i, j));
				ans = max(ans, f(str, j, i));
			}
		}		

		cout << (int)str.size() - ans << "\n";
	}
}