#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int abs(int x) {return x < 0 ? -x : x;}

int p[100001], h[100001];
vector<int> v[100001];

bool hasAns = true;
int f(int node) {
	if(v[node].size() == 0) {
		if(abs(h[node]) != p[node]) hasAns = false;
		return h[node];
	}

	int mn = -p[node];
	int mx = p[node];
	for(int i : v[node]) {
		int value = f(i);
		mn += value;
		mx += abs(value);
	}

	if(mn <= h[node] && h[node] <= mx) {
		return h[node];
	} else {
		if(node != 1)  {
			hasAns = false;
		}
		return -1000000000;
	}
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m; scanf("%d %d", &n, &m);
		for(int i=1;i<=n;i++) {
			scanf("%d", &p[i]);
		}
		for(int i=1;i<=n;i++) {
			scanf("%d", &h[i]);
		}
		for(int i=0;i<n-1;i++) {
			int s, e;
			scanf("%d %d", &s, &e);
			v[s].push_back(e);
		}

		int x = f(1);
		if(hasAns) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
}