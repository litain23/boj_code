#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		vector<int> v;
		for(int i=1;i<=n;i++) {
			int t; scanf("%d", &t);
			v.push_back(t);
		}

		sort(v.begin(), v.end());

		int ans = 0;
		int e = 0, eCnt = 0;
		for(int i=0;i<n;i++) {
			e = v[i];
			eCnt++;

			if(e <= eCnt) {
				eCnt = 0;
				ans++;
			} 
		}

		cout << ans << "\n";
	}
}