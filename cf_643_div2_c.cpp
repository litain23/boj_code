#include <iostream>
#include <algorithm>
using namespace std;

int sum(int n) {
	return n * (n + 1) / 2;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int diffBC = c - b + 1;
	int ans = 0;

	for(int i=c;i<=b+c-1;i++) {
		int x = c+1-b;
		int tt = (b - max(a, x) + 1) * (c-b+1);
		if(tt > 0) ans += tt;

		tt = (x - a) * a;
		if(tt >0) ans += tt;
	}

	cout << ans;

}