#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		if(n % 4 == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}	
}