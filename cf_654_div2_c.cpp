#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;


int main() {
	int tc; cin >> tc;
	while(tc--) {
		ll v, c, n, m;
		scanf("%lld %lld %lld %lld", &v, &c, &n, &m);

		// a = vanilla
		// b = chocolate
		// n = more or 
		// m = less

		if(v + c < n + m) {
			printf("No\n");
			continue;
		}

		if(v < c) {
			ll diff = c - v;
			ll eat = min(diff, n);
			c -= eat;
			n -= eat;

			if(v < c) {
				if(v - m < 0) {
					printf("No\n");
					continue;
				} else {
					printf("Yes\n");
					continue;
				}
			}
		}

		if(c < v) {
			ll diff = v - c;
			ll eat = min(diff, n);
			v -= eat;
			n -= eat;

			if(c < v) {
				if(c < m) {
					printf("No\n");
					continue;
				} else {
					printf("Yes\n");
					continue;
				}
			}
		}		


		if(c == v) {
			if(min(c, v) < m) {
				printf("No\n");
				continue;
			} else {
				printf("Yes\n");
				continue;
			}
		}

	}
}