#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		cin >> str;

		string ans = "";
		for(int i=0;i<str.size();i+=2) {
			ans.push_back(str[i]);
		}

		ans.push_back(str[str.size()-1]);
		cout << ans << "\n";

	}
}