#include <iostream>
#include <vector>
#include <string>	
#include <algorithm>
using namespace std;

int a[101];

char f(char c) {
	for(char i='a';i<='z';i++) {
		if(i != c) return i;
	}
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		int mx = 0;
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			mx = max(mx, a[i]);
		}


		vector<string> v;
		string str;
		for(int i=0;i<=mx;i++) {
			str.push_back('a');
		}
		v.push_back(str);

		for(int i=0;i<n;i++) {
			int t = a[i];
			string last = v[v.size()-1];
			while(str.size() > t) {
				str.pop_back();
			}

			// cout << str << endl;

			for(int j=t;j<=mx;j++) {
				str.push_back(f(last[j]));
			}
			v.push_back(str);
		}

		for(string s : v) {
			cout << s << "\n";
		}
	}	
}