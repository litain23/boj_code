#include <iostream>
using namespace std;

int a[40];

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n;
		scanf("%d", &n);

		int even = 0, odd = 0;
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
			if(a[i] % 2) odd++;
			else even++;
		}

		if(n % 2) {
			if(even - 1 != odd) {
				printf("-1\n");
				continue;
			}
		} else {
			if(even != odd) {
				printf("-1\n");
				continue;
			}
		}

		int ans = 0;
		for(int i=1;i<n;i+=2) {
			if(a[i] % 2 == 0) ans++;
		}

		cout << ans << "\n";

	}
}