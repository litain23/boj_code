#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, x, m;
		cin >> n >> x >> m;

		int start = x, end = x;
		for(int i=0;i<m;i++) {
			int l, r;
			scanf("%d %d", &l, &r);

			if(start <= r && l <= end) {
				start = min(l, start);
				end = max(r, end);
			} 
		}

		cout << end - start + 1 << "\n";
	}

}