#include <iostream>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);

		if(n == 1) {
			printf("%d\n", 0);
		} else if(n == 2) {
			printf("%d\n", m);
		} else {
			printf("%d\n", 2 * m);
		}
	}
}