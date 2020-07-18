#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		int mx = max({x, y, z});
		int mn = min({x, y, z});
		int cnt = 0;
		if(mx == x) cnt++;
		if(mx == y) cnt++;
		if(mx == z) cnt++;

		if(cnt <= 1) {
			cout << "NO\n";
		} else {
			printf("YES\n");
			printf("%d %d %d\n", mx, mn, mn);
		}
	}
}