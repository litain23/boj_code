#include <iostream>
using namespace std;

int a[100005];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		int firstOneCnt = 0;
		int i;
		for(i=1;i<=n;i++) {
			if(a[i] != 1) break;
			else firstOneCnt++;
		}

		int oneCnt = 0, otherCnt = 0;
		for(;i<=n;i++) {
			if(a[i] == 1) oneCnt++;
			else otherCnt++;
		}

		bool ans;
		// true first;
		// false second;
		if(firstOneCnt == n) {
			if(n % 2) {
				printf("First\n");
			} else {
				printf("Second\n");
			}
		} else {
			if(firstOneCnt % 2) {
				ans = false;
			} else {
				ans = true;
			}
			if(ans) {
				printf("First\n");
			} else {
				printf("Second\n");
			}
		}
	}
}