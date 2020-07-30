#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
string f(string str, int n) {
	string ret = "";
	for(int i=0;i<str.size();i++) {
		if(i <= n) {
			if(str[i] == '0') ret.push_back('1');
			else ret.push_back('0');
			if(i == n) reverse(ret.begin(), ret.end());
		} else {
			ret.push_back(str[i]);
		}
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
		while(idx >= 1) {
			if(a[idx] != b[idx]) {
				if(a[0] == b[idx]) {
					v.push_back(1);
					cnt++;
					if(a[0] == '1') a[0] = '0';
					else a[0] = '1';
				}
 
				a = f(a, idx);
				v.push_back(idx + 1);
				cnt++;
			}	
			// cout << a << endl;
			idx--;
		}
 
		if(a[0] != b[0]) {
			v.push_back(1);
			cnt++;
		}
 
		printf("%d ", cnt);
		for(int i : v) {
			printf("%d ", i);
		}
		puts("");
 
 
	}
}