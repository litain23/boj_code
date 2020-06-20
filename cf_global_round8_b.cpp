#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
int a[10];

ll pow10(ll x) {
	ll ret = 1LL;
	for(int i=0;i<10;i++) {
		ret *= x;
	}
	return ret;
}

ll sum() {
	ll ret = 1LL;
	for(int i=0;i<10;i++) {
		ret *= a[i];
	}
	return ret;
}

int main() {
	ll n;
	cin >> n;
	if(n == 1) {
		cout << "codeforces";
		return 0;
	}

	for(ll i=0;;i++) {
		ll temp = pow10(i);
		if(n <= temp) {
			for(int j=0;j<10;j++) {
				a[j] = (int)i;
			}

			for(int j=0;j<10;j++) {
				a[j]--;
				ll ret = sum();
				if(ret < n) {
					a[j]++;
					break;
				}
			}
			break;
		} 
	}

	string str = "codeforces";
	for(int i=0;i<10;i++) {
		for(int j=0;j<a[i];j++) {
			printf("%c", str[i]);
		}
	}
}

