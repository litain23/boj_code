#include <iostream>
#include <string>
using namespace std;

int a[51];

int pow(int x) {
	return x < 0 ? -x : x;
}

char findMaxChar(string &str, char c) {
	int mx = 65, mxIdx = 0;
	for(int i=0;i<str.size();i++) {
		if(mx < str[i] && str[i] < c) {
			mx = str[i];
			mxIdx = i;
		}
	}

	return mx;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		int n; 
		cin >> str >> n;
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
		}

		char ans[51];
		for(int i=0;i<51;i++) ans[i] = 0;

		char last;
		for(int i=0;i<n;i++) {
			int mn = 5000, mnIdx = 0;
			for(int j=0;j<n;j++) {
				if(a[j] < mn) {
					mnIdx = j;
					mn = a[j];
				}
			}

			int diff = a[mnIdx];
			if(diff == 0) {
				ans[mnIdx] = findMaxChar(str, 'z' + 1);
				last = ans[mnIdx];
			} else {
				ans[mnIdx] = findMaxChar(str, last);
				int sumIdx = 0;
				for(int j=0;j<n;j++) {
					if(ans[mnIdx] > ans[j]) {
						sumIdx += pow(j - mnIdx);
					}
				}

				int cnt = 1;
				while(sumIdx != mn) {
					ans[mnIdx] = findMaxChar(str, last + cnt++);
					sumIdx = 0;
					for(int j=0;j<n;j++) {
						if(ans[mnIdx] > ans[j]) {
							sumIdx += pow(j - mnIdx);
						}
					}

				}

				last = ans[mnIdx];
			}

			for(int i=0;i<n;i++) {
				if(str[i] == last) {
					str[i] = 65;
					break;
				}
			}

			a[mnIdx] = 5000;
		}

		for(int i=0;i<n;i++) {
			cout << str[i];
		}
		puts("");

	}
}