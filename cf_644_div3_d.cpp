#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin	>> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		int ans = 0x3f3f3f3f;

		int sqrtn = ceil(sqrt(n));
		if(n <= k) {
			printf("1\n");	
		} else {
			for(int i=min(sqrtn, k);i>=1;i--) {
				if(n % i == 0) {
					int mok = n / i;
					if(mok <= k) {
						ans = min(ans, min(i , mok));
					} else {
						ans = min(ans, mok);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
}