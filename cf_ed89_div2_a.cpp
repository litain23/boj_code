#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int a, b, ans = 0;
		cin >> a >> b;

		if(a < b) swap(a, b);

		int diff = a - b;
		ans += min(b, diff);
		a -= 2 * min(b, diff);
		b -= min(b, diff);

		if(b != 0) {
			ans += (a / 3) * 2;
			if(a % 3 == 2) ans++;
		}
		cout << ans << "\n";
	}
}