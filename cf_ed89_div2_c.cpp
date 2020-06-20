#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mp[31][31];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(m < n) scanf("%d", &mp[j][i]);
				else scanf("%d", &mp[i][j]);
			}
		}

		if(m < n) swap(n, m);

		int ans = 0;
		for(int sum=2;sum<=(n+m-1)/2+1;sum++) {
			int i = 1;
			int j = sum - i;

			int zeroCnt = 0;
			int oneCnt = 0;
			int cnt = 0;
			while(j >= 1 && i <= n) {
				cnt++;
				if(mp[i][j]) oneCnt++;
				else zeroCnt++;

				if(mp[n+1-i][m+1-j]) oneCnt++;
				else zeroCnt++;
				i++;
				j--;
			}	
			ans += min(cnt * 2 - oneCnt, cnt * 2 - zeroCnt);
		}
		cout << ans << "\n";
	}
}