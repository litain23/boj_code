#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> mp;
map<int, int> mxCnt;

vector<int> f() {
	vector<int> ret;
	for(int i=8;i>=1;i--) {
		if(ret.size() > 4) break;
		for(int j=0;j<mxCnt[i];j++) {
			ret.push_back(i);
		}
	}
	return ret;
}
int main() {
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		int t; scanf("%d", &t);
		mp[t]++;
		int c = mp[t];
		if(c > 8) {
			mxCnt[8]++;
		} else {
			mxCnt[c]++;
			mxCnt[c-1]--;
		}
	}

	// for(int i=1;i<=8;i++) {
	// 	cout << mxCnt[i] << endl;
	// }

	int q; cin >> q;
	for(int i=0;i<q;i++) {
		char c;
		int t;
		scanf(" %c %d", &c, &t);

		if(c == '+') {
			mp[t]++;
			int ct = mp[t];
			// cout << ct << endl;
			if(ct > 8) {
				mxCnt[8]++;
			} else {
				mxCnt[ct]++;
				if(mxCnt[ct-1] > 0) mxCnt[ct-1]--;
			}
		} else {
			mp[t]--;
			int ct = mp[t];
			if(ct >= 8) {
				mxCnt[8]--;
			} else {
				if(mxCnt[ct+1] > 0) mxCnt[ct+1]--;
				mxCnt[ct]++;
			}
		}

		

		vector<int> ans = f();
		if( (ans.size() >= 1 && ans[0] == 8) ||
			(ans.size() >= 2 && ans[0] >= 6 && ans[1] >= 2) ||
			(ans.size() >= 2 && ans[0] >= 4 && ans[1] >= 4) ||
			(ans.size() >= 3 && ans[0] >= 4 && ans[1] >= 2 && ans[2] >= 2) ) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

		// for(int x : ans ) {
		// 	cout << x << endl;
		// }
		// cout << endl;

	}
}