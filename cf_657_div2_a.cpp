#include <iostream>
#include <string>
using namespace std;

int isOk(string str, int index) {
	// 1 = OK
	// 0 = ? 포함한 OK
	// -1 = falsoe
	string ckStr = "abacaba";
	// if(str.size() - index < 7) return false;

	int ret = 1;
	int j = -1;
	for(int i=index;i<index+7;i++) {
		j++;
		if(str[i] == '?') {
			ret = 0;
			continue;
		}

		if(ckStr[j] != str[i]) return -1;
	}

	return ret;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		string str;
		cin >> str;

		int ans = 0;
		int mayBeAns = 0;
		for(int i=0;i<=n-7;i++) {
			int ok = isOk(str, i);
			if(ok == 1) ans++;
			else if(ok == 0) mayBeAns++;
		}
dd
		if(ans == 1) {
			string ans = "";
			for(char c : str) {
				if(c == '?') ans.push_back('d');
				else ans.push_back(c);
			}
			cout << "Yes\n" << ans << "\n";
		} else if(ans >= 2) {
			cout << "No\n";

		} else if(ans == 0 && mayBeAns >= 1) {
			int i;
			for(i=0;i<=n-7;i++) {
				if(isOk(str, i) == 0) {
					break;
				}
			}

			string ans = "";
			for(int j=0;j<str.size();j++) {
				if(j == i) {
					ans += "abacaba";
					j += 6;
				} else {
					if(str[j] == '?') ans.push_back('d');
					else ans.push_back(str[j]);
				}
			}
			cout << "Yes\n" << ans << "\n";
		} else {
			cout << "No\n";
		}
	}
}