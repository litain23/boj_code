#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n;
		scanf("%d", &n);

		for(int i=n;i>=1;i--) {
			printf("%d ", i);
		}
		puts("");
	}	
}