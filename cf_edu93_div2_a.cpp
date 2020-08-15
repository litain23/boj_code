#include <iostream>
using namespace std;

int a[50005];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		if(a[1] + a[2] <= a[n]) {
			printf("1 2 %d\n", n);
		} else {
			printf("-1\n");
		}
	}
}