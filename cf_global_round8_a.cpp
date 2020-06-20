#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int a, b, n;
		cin >> a >> b >> n;

		int sum = 0, ans = 0;
		while(1) {
			if(a < b) {
				a += b;
			} else {
				b += a;
			}

			ans++;
			if(a > n || b > n) break;	
		}	

		cout << ans << "\n";

			
	}
}