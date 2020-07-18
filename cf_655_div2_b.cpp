#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		if(n % 2) {
			bool hasAns = false;
			for(int i=3;i<=32000;i+=2) {
				if(n % i == 0) {
					printf("%d %d\n", n / i, (i - 1) * (n / i));
					hasAns = true;
					break;
				}
			}
			if(!hasAns) {
				printf("%d %d\n", 1, n - 1);
			}
		} else {
			printf("%d %d\n", n / 2,  n / 2);
		}
	}
}