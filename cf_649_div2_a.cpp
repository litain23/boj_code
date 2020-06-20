#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, x;
		cin >> n >> x;

		bool hasAns = false;
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			if(a[i] % x) hasAns = true;
		}

		if(!hasAns) {
			printf("-1\n");
			continue;
		}

		int ans = 0, sum = 0;
		for(int i=1;i<=n;i++) {
			sum += a[i];
			if(sum % x) {
				ans = i;
			}
		}

		sum = 0;
		for(int i=n;i>=1;i--) {
			sum += a[i];
			if(sum % x) {
				ans = max(n-i+1, ans);	
			}
		}

		cout << ans << "\n";
	}
}