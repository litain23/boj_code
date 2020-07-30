#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int l, r, m;
		cin >> l >> r >> m;

		int mxBc = r - l;

		for(int i=l;i<=r;i++) {
			int namoji = m % i;
			int mok = m / i;



			if(mok == 0) {
				if(m - i >= l - r) {
					int b = l;
					int c = l - (m - i);
					printf("%d %d %d\n", i, b, c);
					break;
				}
			} else {
				if(namoji <= mxBc) {
					int b = r;
					int c = r - namoji;
					printf("%d %d %d\n", i, b, c);
					break;
				} else if(i - (r - l) <= namoji) {
					// namoji - i 
					int b = r - (i - namoji);
					int c = r;
					printf("%d %d %d\n", i, b, c);
					break;
				}
			}
		}
	}
}