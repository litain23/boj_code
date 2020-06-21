#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2001];
int isPrime[2001];
vector<int> prime;
int main() {
	for(int i=2;i<=50;i++) {
		if(isPrime[i]) continue;
		for(int j=i*2;j<=2000;j+=i) {
			isPrime[j] = true;
		}
	}
	for(int i=2;i<=2000;i++) {
		if(!isPrime[i]) prime.push_back(i);
	}

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i=1;i<=2*n;i++) {
			scanf("%d", &a[i]);
		}

		if(n == 2) {
			printf("1 2\n");
			continue;
		}

		bool ck[2001];
		vector<pair<int,int>> ans;
		for(int gcd : prime) {
			memset(ck, 0, sizeof(ck));
			ans.clear();
			// printf("gcd : %d\n", gcd);
			for(int i=1;i<2*n;i++) {
				// printf("i = %d\n", i);
				if(ck[i]) continue;
				for(int j=i+1;j<=2*n;j++) {
					if(ck[j]) continue;
					// printf("j = %d\n", j);
					if((a[i] + a[j]) % gcd == 0) {
						ans.push_back(make_pair(i, j));
						ck[i] = ck[j] = true;
						// printf("%d %d\n", a[i], a[j]);
						break;
					}
				}

				if(ans.size() == n - 1) break;
			}

			if(ans.size() == n -1) {
				for(auto i : ans) {
					printf("%d %d\n", i.first, i.second);
				}
				break;
			}
		}
	}
}