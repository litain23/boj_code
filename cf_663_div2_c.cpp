#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1e9+7;

int main() {
	long long n; cin >> n;

	long long p = 1LL;
	for(int i=1;i<=n;i++) {
		p *= i;
		p %= MOD;
	}

	long long n2 = 1LL;
	long long sum = 0LL;
	for(int i=0;i<n-1;i++) {
		n2 *= 2;
		n2 %= MOD;
	}

	if(p < n2) {
		p = MOD + p - n2;
	} else {
		p = p - n2;
	}

	cout << p;
}