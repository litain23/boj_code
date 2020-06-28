#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int a, b, c;		
		scanf("%d %d %d", &a, &b, &c);

		if(c <= a) {
			printf("-1 %d\n", b);
		} else if(b <= (double) c / a) {
			printf("1 -1\n");
		} else {
			printf("1 %d\n", b);
		}
	}
}