#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		long long n, r;
		scanf("%lld %lld", &n, &r);

		long long ans;
		if(n <= r) {
			ans = n * (n - 1) / 2 + 1;
		} else {
			ans = r * (r + 1) / 2;
		}
		printf("%lld\n", ans);
	}
}