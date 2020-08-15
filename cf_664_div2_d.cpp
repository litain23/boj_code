#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

vector<ll> muzzle, pass;

ll getLastSum(int d) {
	ll sum = 0LL;
	for(int i=0;i<pass.size();i++) {
		sum += pass[i];
	}
	return sum;
}
int main() {
	int n, d, m;
	cin >> n >> d >> m;

	for(int i=1;i<=n;i++) {
		int t; scanf("%d", &t);
		if(t >= m) {
			muzzle.push_back(t);
		} else {
			pass.push_back(t);
		}
	}

	sort(muzzle.rbegin(), muzzle.rend());
	sort(pass.rbegin(), pass.rend());

	queue<ll> q;
	for(ll i : muzzle) {
		q.push(i);
	}

	int remaindDay = n;
	ll ans = 0LL;
	while(remaindDay > 0) {
		ll mxMuzzle = q.front();

		if(remaindDay < d) {
			ll passSum = 0;
			for(int i=0;i<d-1;i++) {
				passSum += pass[i];
			}
			ans += passSum;
			ans += mxMuzzle;
			break;
		}

		ll passSum = getLastSum(d);
		if(mxMuzzle > passSum) {
			q.pop();
			remaindDay -= (d + 1);
			ans += mxMuzzle;
		} else {
			ans += pass[0];
			pass = {pass.begin() + 1, pass.end()};
			// for(int i=0;i<d;i++) {
			// 	pass.pop_back();
			// }
			remaindDay -= 1;
		}
	}
	cout << ans;

}