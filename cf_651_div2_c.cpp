#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;

		int twoCnt = 0;
		int oddCnt = 0;

		if(n == 1) {
			printf("FastestFinger\n");
		} else if(n == 2) {
			printf("Ashishgup\n");
		} else if(n % 2 == 1) {
			printf("Ashishgup\n");
		} else {
			while(n % 2 == 0) {
				twoCnt++;
				n /= 2;
			}

			for(int i=3;i<=32000;i+=2) {
				if(n == 0) break;
				while(n % i == 0) {
					oddCnt++;
					n /= i;
				}
			}

			if(n > 32000) oddCnt++;

			if(twoCnt == 1 && oddCnt >= 2) {
				printf("Ashishgup\n");
			} else if(twoCnt == 1 && oddCnt == 1) {
				printf("FastestFinger\n");
			} else if(twoCnt >= 2 && oddCnt >= 1) {
				printf("Ashishgup\n");
			} else if(twoCnt >= 2 && oddCnt == 0) {
				printf("FastestFinger\n");
			}
		}
	}
}