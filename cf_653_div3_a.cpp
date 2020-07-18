#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int x, y, n;
		scanf("%d %d %d", &x, &y, &n);

		int remainder = n / x;
		int moduler = n % x;

		int ans = 0;
		if(y <= moduler) {
			ans = n - (moduler - y);
		} else {
			remainder -= 1;
			// moduler += x;
			ans = n - (moduler + x - y);
		}

		cout << ans << "\n";


	}
}