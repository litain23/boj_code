#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, b;
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		int t; cin >> t;
		a.push_back(t);
	}
	for(int i=0;i<m;i++) {
		int t; cin >> t;
		b.push_back(t);
	}

	sort(b.begin(), b.end());
	sort(a.rbegin(), a.rend());


	for(int ans=0;ans<512;ans++) {
		int tmpAns = ans;
		bool isAns = true;
		for(int i : a) {
			bool isInAns = false;
			for(int j : b) {
				if( ((i & j) | tmpAns) == tmpAns) {
					isInAns = true;
					break;
				}
			}
			if(!isInAns) {
				isAns = false;
				break;
			}
		}
		if(isAns) {
			cout << ans;
			break;
		}
	}


}