#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		vector<int> v;
		int n;
		cin >> n;

		int evenCnt = 0, oddCnt = 0;
		for(int i=0;i<n;i++) {
			int t; scanf("%d", &t);
			if(t % 2) {
				oddCnt++;
			} else {
				evenCnt++;
			}

			v.push_back(t);
		}

		if(oddCnt % 2 == 0 && evenCnt % 2 == 0) {
			printf("YES\n");
		} else {
			bool isOne = false;
			sort(v.begin(), v.end());
			for(int i=1;i<n;i++) {
				if(v[i] -v[i-1] == 1) {
					isOne = true;
					break;
				}
			}

			if(isOne) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}

	}	
}