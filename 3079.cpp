//3079.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;
ll f(ll ans){
	ll isAns = 0LL;
	for(ll i : v) isAns = isAns + ans / i;
	return isAns;
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	v.resize(n);
	for(int i=0;i<n;i++) scanf("%lld", &v[i]);

	ll start = 0LL, end = 1e18;
	for(int i=0;i<65;i++){
		ll mid = (start+end)/2;
		ll isAns = f(mid);
		if(isAns < m) start = mid +1LL;
		else end = mid - 1LL;
	}
	printf("%lld", start);
}