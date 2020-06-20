#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

ll a[200001];
int main() {
	map<int,int> mp;
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		scanf("%lld", &a[i]);
	}

	sort(a, a + n);
	ll mx = a[n-1];
	for(int i=0;i<n-1;i++) {
		ll orTemp = mx | a[i];
		ll andTemp = mx & a[i];

		// if(orTemp * orTemp + andTemp * andTemp < mx * mx + a[i] * a[i]) {
		// 	continue;
		// } 

		mx = orTemp;
		a[i] = andTemp;
	}

	a[n-1] = mx;

	ll ans = 0LL;
	for(int i=0;i<n;i++) {
		// cout << a[i] << endl;
		ans += a[i] * a[i];
	}

	cout << ans;

}