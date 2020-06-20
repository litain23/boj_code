#include <iostream>
#include <vector>
using namespace std;


int pow(int x) {
	return x < 0 ? -x : x;
}

int a[100001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		vector<int> ans;
		for(int i=1;i<=n;i++) {
			if(ans.size() < 2) ans.push_back(a[i]);
			else {
				int ansSize = ans.size();
				int before = ans[ansSize - 1];
				int beforebefore = ans[ansSize - 2];

				if(beforebefore < before && before < a[i]) {
					ans.pop_back();
					ans.push_back(a[i]);
				} else if(beforebefore > before && before > a[i]) {
					ans.pop_back();
					ans.push_back(a[i]);
				} else {
					ans.push_back(a[i]);
				}
			}
		}

		printf("%d\n", ans.size());
		for(int i : ans) {
			printf("%d ", i);
		}
		puts("");


	}	
}