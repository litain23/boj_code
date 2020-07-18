#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[200005], n;

bool isAns(int start) {
	int end = n;
	int cnt = 0;
	int value = min(a[start], a[end]);
	while(start != end) {
		if(a[start] < a[end] && a[start] >= value) {
			value = a[start];
			start++;
		} else if(a[start] >= a[end] && a[end] >= value) {
			value = a[end];
			end--;
		} else {
			return false;
		}
	}
	return true;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}

		int start = 0, end = n + 1;
		int mid;
		while(start + 1 < end) {
			mid = (start + end) / 2;
			if(isAns(mid)) {
				end = mid;
			} else {
				start = mid;
			}
		}
		printf("%d\n", start);
	}	
}