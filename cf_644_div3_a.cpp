#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int x = max(min(a, b) * 2 , max(a, b));
		printf("%d\n", x * x);

	}
}