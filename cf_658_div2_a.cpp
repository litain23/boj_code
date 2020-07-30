#include <iostream>
#include <map>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);

		map<int, int> mp;
		for(int i=0;i<n;i++) {
			int t; scanf("%d", &t);
			mp[t]++;	
		}

		bool hasAns = false;
		int ans;
		for(int i=0;i<m;i++) {
			int t; scanf("%d", &t);
			if(mp[t]) {
				hasAns = true;
				ans = t;
			}
		}

		if(hasAns) {
			printf("YES\n1 %d\n", ans);
		} else {
			printf("NO\n");
		}
	}
}