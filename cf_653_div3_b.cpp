#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		int twoCnt = 0, threeCnt = 0;

		if(n == 1) {
			printf("0\n");
			continue;
		}

		bool hasAns = true;
		while(n >= 2) {
			if(n % 2 == 0) {
				n /= 2;
				twoCnt++;
			} else if(n % 3 == 0) {
				n /= 3;
				threeCnt++;
			} else {
				hasAns = false;
				break;
			} 
		}



		if(threeCnt < twoCnt || !hasAns) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", (threeCnt - twoCnt) + threeCnt);

	}
}