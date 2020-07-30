#include <iostream>
#include <vector>
#include <string>	
#include <algorithm>
#include <queue>
using namespace std;

int depth[101];
int tide[200];

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, k, l;
		cin >> n >> k >> l;

		int maxDepth = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d", &depth[i]);
			maxDepth = max(depth[i], maxDepth);
		}

		int t = 0;
		for(int i=0;i<2*k;i++) {
			tide[i] = t;
			if(i >= k) t--;
			else t++;
		}
		for(int i=0;i<2*k;i++) {
			cout << tide[i] << endl;
		}

	}	
}