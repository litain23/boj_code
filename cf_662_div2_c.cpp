#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;


int a[100001];
int n;
bool f(vector<int>& v, int value) {
	bool m[100001];
	memset(m, 0, sizeof(m));
	int start = 1;
	for(int x : v) {
		// cout << "X : " << x << endl;
		int sum = start;
		if(m[sum]) {
			return false;
		}
		for(int i=0;i<x-1;i++) {
			// cout << sum << endl;
			m[sum] = true;
			sum += value;
			if(sum > n || m[sum]) {
				return false;
			} 
		} 
		start++;
	}
	return true;
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		memset(a, 0, sizeof(a));
		vector<int> v;
		scanf("%d", &n);
		for(int i=0;i<n;i++){ 
			int t; scanf("%d", &t);
			a[t]++;
		}


		sort(a, a + 100000);
		for(int i=100000;i>=0;i--) {
			if(a[i]) {
				// cout << a[i];
				v.push_back(a[i]);
			} 
		}

		int start = 0, end = n;
		int mid;
		
		
		
		while(start + 1 < end) {
			mid = (start + end) / 2;

			bool isOk = f(v, mid);
			if(isOk) {
				start = mid;
			} else {
				end = mid - 1;
			}
		}

		cout << start << endl;

	}
}