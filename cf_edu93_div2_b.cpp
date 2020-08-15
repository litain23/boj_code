#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		cin >> str;

		int startZero = 0;
		int startOne = 0;
		int sz = str.size();

		vector<string> v;

		string one = "";
		for(int i=0;i<sz;i++) {
			if(str[i] == '1') {
				one.push_back('1');
			} else {
				if(one == "") continue;
				v.push_back(one);
				one = "";
			}
		}
		v.push_back(one);

		sort(v.rbegin(), v.rend());
		bool toggle = true;
		int ans = 0;
		for(string str : v) {
			if(toggle) {
				ans += str.size();
				toggle = !toggle;
			} else {
				toggle = !toggle;
			}
		}
		cout << ans << "\n";

	}
}