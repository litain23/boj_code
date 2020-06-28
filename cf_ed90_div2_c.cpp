#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		cin >> str;

		int cur = 0;
		long long ans = 0LL;
		int minusCnt = 0, plusCnt = 0;
		for(int i=0;i<str.size();i++) {
			char c = str[i];
			if(c == '+') {
				plusCnt++;
			} else {
				minusCnt++;
				if(plusCnt < minusCnt) {
					cur++;
					ans += (i + 1);
					plusCnt ++;
				}
			}
		}
		ans += str.size();
		cout << ans << "\n";

	}
}