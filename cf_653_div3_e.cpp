#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

const int MAX_N = 2e5 + 3;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> a, b, c;
	
	for(int i=1;i<=n;i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		if(y == 1 && z == 1) {
			c.push_back(make_pair(x, i));
		} else if(y == 1) {
			a.push_back(make_pair(x, i));
		} else if(z == 1) {
			b.push_back(make_pair(x, i));
		}
	}	

	if(c.size() + a.size() < k || c.size() + b.size() < k) {
		printf("-1");
		return 0;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int ans = 0;
	// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> inA, inB;
	priority_queue<pair<int,int>> inA, inB;

	for(int i=0;i<min((int)a.size(), k);i++) {
		inA.push(make_pair(0, a[i].first));
		ans += a[i].first;
	}
	for(int i=0;i<min((int)b.size(), k);i++) {
		inB.push(make_pair(0, b[i].first));
		ans += b[i].first;
	}

	int cIdx = 0;
	while(inA.size() < k) {
		int value = c[cIdx].first;
		int popValue = 0;
		inA.push(make_pair(-1, value));
		if(inB.size() == k) {
			popValue = inB.top().second;
			// printf("pop value : %d\n", popValue);
			inB.pop();
		} 
		inB.push(make_pair(-1, value));
		cIdx++; 
		ans -= popValue;
		ans += value;
		// printf("ans : %d popValue : %d value : %d\n", ans, popValue, value);
	}


	while(inB.size() < k) {
		int value = c[cIdx].first;
		int popValue = 0;
		inB.push(make_pair(-1, value));
		if(inA.size() == k) {
			int popValue = inA.top().second;
			inA.pop();
			inA.push(make_pair(-1, value));
		} else {
			inA.push(make_pair(-1, value));	
		}
		cIdx++; 
		if(popValue != 0) {
			ans -= popValue;
		}
		ans += value;
			
	}

	cout << ans;


}

