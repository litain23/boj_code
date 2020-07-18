#include <iostream>
using namespace std;

int a[200001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		int sameCnt = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			if(a[i] == i) sameCnt++;
		}

		if(sameCnt == n) {
			printf("0\n");
		} else if(sameCnt == 0) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
}