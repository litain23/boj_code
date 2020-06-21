#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		if(n <= 3) {
			printf("1\n");
		} else {
			if(n % 2) {
				printf("%d\n", (n-1) / 2);
			} else {
				printf("%d\n", n / 2);
			}
		}
	}	
}