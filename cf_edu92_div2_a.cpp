#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int l, r;
		scanf("%d %d", &l, &r);

		if(l * 2 <= r) {
			printf("%d %d\n", l, l * 2);
		} else {
			printf("-1 -1\n");
		}
	}
}