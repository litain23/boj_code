#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		if(n == 36) {
			printf("YES\n15 10 6 5\n");
		} else if(n == 40) {
			printf("YES\n15 10 6 9\n");
		} else if(n == 44) {
			printf("YES\n15 10 6 13\n");
		} else if(n >= 31) {
			printf("YES\n14 10 6 %d\n", n - 30);
		} else {
			printf("NO\n");
		}
	}	
}