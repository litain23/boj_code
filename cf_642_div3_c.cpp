#include <iostream>
using namespace std;

long long a[250001];
int main() {
	a[1] = 0LL;
	for(long long i=2;i<=250000;i++) {
		a[i] = (i - 1) * ((i * 2 - 1) * (i * 2 - 1) - (i * 2 - 3) * (i * 2 - 3)) + a[i-1];
	}


	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		printf("%lld\n", a[n / 2 + 1]);
	}
}