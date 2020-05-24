#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		vector<int> v;
		for(int i=0;i<n;i++) {
			int t; scanf("%d", &t);
			v.push_back(t);
		}

		sort(v.begin(), v.end());
		int diff = 1001;
		for(int i=1;i<n;i++) {
			diff = min(diff, v[i] - v[i-1]);
		}

		printf("%d\n", diff);

	}
}