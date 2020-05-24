#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> getMinMaxDigit(long long a) {
	int mn = 10;
	int mx = 0;
	while(a != 0) {
		int n = a % 10;
		mn = min(mn, n);
		mx = max(mx, n);
		a /= 10;
	}

	return {mn, mx};
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		long long a, k;
		scanf("%lld %lld", &a, &k);

		for(long long i=0LL;i<k-1;i++) {
			pair<int, int> mnmx = getMinMaxDigit(a);			
			if(mnmx.first == 0) {
				break;
			}
			a = a + mnmx.first * mnmx.second;
		}
		cout << a << "\n";
	}
}