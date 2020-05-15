#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		priority_queue<int> aPQ, bPQ;
		int n, k;
		int aSum = 0;
		scanf("%d %d", &n, &k);
		for(int i=1;i<=n;i++) {
			int t; scanf("%d", &t);
			aSum += t;
			aPQ.push(-t);
		}

		for(int i=1;i<=n;i++) {
			int t; scanf("%d", &t);
			bPQ.push(t);
		}

		int cnt = 0;
		while(-aPQ.top() < bPQ.top() && cnt < k) {
			int aValue = -aPQ.top(); aPQ.pop();
			int bValue = bPQ.top(); bPQ.pop();
			aSum += (bValue - aValue);
			aPQ.push(-bValue);
			bPQ.push(aValue);
			cnt++;
		}

		printf("%d\n", aSum);
	}
}