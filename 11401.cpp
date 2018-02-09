//11401.cpp
#include <cstdio>

typedef long long ll;
const ll MOD = 1e9+7LL;

ll fac[4000001], n, k, inv[4000001];

ll power(ll x, ll y){
	ll ret = 1LL;
	while(y > 0){
		if(y % 2){
			ret *= x;
			ret %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return ret;
}

int main(){
	scanf("%lld %lld", &n, &k);
	fac[1] = 1LL;
	for(int i=2;i<=n;i++) fac[i] = (fac[i-1] * i) % MOD;

	inv[n] = power(fac[n], MOD - 2LL);
	for(int i=n-1;i>=1;i--){
		inv[i] = (inv[i+1] * (i+1)) % MOD;
	}

	if(n == k || k == 0){
		printf("1");
		return 0;
	}
	ll ans = fac[n] * inv[n-k] % MOD;
	ans = (ans * inv[k]) % MOD;
	printf("%lld", ans);
}