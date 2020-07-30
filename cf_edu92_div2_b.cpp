#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100005];
int sum[100005];

int f(int x) {
	if(x < 0) return -100;
	int ret = 0;
	for(int i=1;i<=x;i++) {
		ret = max(a[i] + a[i+1], ret);
	}	
	return ret;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, k, z;
		scanf("%d %d %d", &n, &k, &z);
		memset(sum, 0, sizeof(sum));

		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}

		int ans = 0;

		ans = sum[k + 1]; // 0번

		if(z >= 1) {
			ans = max(sum[min(2, k)] + a[min(1, k-1)], ans); // 1번
			ans = max(sum[min(2, k-1)] + f(min(1, k-2)), ans); // 1번
		} else if(z >= 2) {
			ans = max(sum[min(k-2, 2)] + f(min(1, k-3)) + a[min(1, k-3)], ans); // 2번
			ans = max(sum[min(k-3, 2)] + 2 * f(min(1, k-4)), ans); // 2번
		} else if(z >= 3) {
			ans = max(sum[min(2, k-4)] + 2 * f(min(1, k-5)) + a[min(1, k-5)], ans); // 1번
			ans = max(sum[min(2, k-5)] + 3 * f(min(1, k-6)), ans); // 1번
		} else if(z >= 4) {
			ans = max(sum[min(2, k-6)] + 3 * f(min(1, k-7)) + a[min(1, k-7)], ans); // 1번
			ans = max(sum[min(2, k-7)] + 4 * f(min(1, k-8)), ans); // 1번
		} else if(z >= 5) {
			ans = max(sum[min(2, k-8)] + 4 * f(min(1, k-9)) + a[min(1, k-9)], ans); // 1번
			ans = max(sum[min(2, k-9)] + 5 * f(min(1, k-10)), ans); // 1번
		}

		printf("%d\n", ans);

	}
}