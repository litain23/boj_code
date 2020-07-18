#include <iostream>
using namespace std;

int a[1001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		printf("%d\n", (n - 1) / 2 + 1);
	}


}