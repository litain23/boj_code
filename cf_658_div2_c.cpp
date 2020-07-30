#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string f(string str) {
	// cout << str << endl;
	string ret = "";
	for(int i=str.size()-1;i>=0;i--) {
		if(str[i] == '1') ret.push_back('0');
		else ret.push_back('1');
	}
	return ret;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		vector<int> v;
		string a, b;
		cin >> a >> b;

		int cnt = 0;

		int idx = n - 1;
		if(a[idx] != b[idx]) {
			if(a[0] == b[idx]) {
				if(a[0] == '1') a[0] = '1';
				else a[0] = '0';
				v.push_back(1);
				cnt++;
			}

			v.push_back(idx + 1);
			cnt++;

			
		}


	}
}