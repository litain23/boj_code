#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		int x = (n - 1) / 4 + 1;
		for(int i=0;i<n-x;i++) {
			printf("9");
		}
		for(int i=0;i<x;i++) {
			printf("8");
		}
		puts("");

	}	
}