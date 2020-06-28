#include <iostream>
#include <algorithm>
using namespace std;

int a[200001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		long long mxDiff = 0, diff = 0;
		int mxStart = 0, mxEnd = 0;
		int start = 1, end = 1;
		for(int i=1;i<=n-1;i+=2) {
			diff += a[i+1] - a[i];
			end = i+1;
			if(mxDiff < diff) {
				mxStart = start;
				mxEnd = end;
				mxDiff = diff;
			} 

			while(diff < 0 && start < end) {
				diff -= a[start+1] - a[start];
				start += 2;
			}
		}

		long long ans1 = 0LL, ans2 = 0LL;
		for(int i=1;i<=n;i+=2) {
			ans1 += a[i];
		}
		ans2 = ans1;
		ans1 += mxDiff;
		// printf("%lld\n", ans1);

		mxDiff = 0, diff = 0;
		mxStart = 0, mxEnd = 0;
		start = 2, end = 2;
		for(int i=2;i<=n-1;i+=2) {
			diff += a[i] - a[i+1];
			end = i+1;
			if(mxDiff < diff) {
				mxStart = start;
				mxEnd = end;
				mxDiff = diff;
			} 

			while(diff < 0 && start < end) {
				diff -= a[start] - a[start+1];
				start += 2;
			}
		}

		// ans2 = ans1;
		ans2 += mxDiff;

		// printf("%lld %lld\n", ans1, ans2);
		printf("%lld\n", max(ans1, ans2));
	}
}