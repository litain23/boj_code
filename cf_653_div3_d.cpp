#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[200001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		map<int,int> mp;
		int n, k; 
		scanf("%d %d", &n, &k);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		bool isAllModZero = true;
		int mxCnt = 0, mnAi = 1e9 + 3;
		for(int i=1;i<=n;i++) {
			int mod = a[i] % k;
			if(mod != 0) {	
				isAllModZero = false;
				mp[mod]++;
				int cnt = mp[mod];
				if(mxCnt < cnt) {
					mxCnt = cnt;
					mnAi = mod; 
				} else if(mxCnt == cnt) {
					mnAi = min(mnAi, mod);
				}
			}
		}

		long long ans = ( ( (long long) mxCnt - 1) * k) + k - mnAi + 1;
		if(isAllModZero) {
			cout << 0 << "\n";
		} else {
			cout << ans << "\n";

		}
	}
}