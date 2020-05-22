#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[2000001];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		memset(d, 0, sizeof(d));
		int n, k;
		string str;
		scanf("%d %d", &n, &k);
		cin >> str;

		int ans = 0;
		for(int i=0;i<n;i++) {
			d[i] = str[i] - '0';

			if(i >= k) {
				d[i] = max(d[i], d[i-k] - 1 + 2 * (str[i] - '0'));
			}
			ans = max(ans, d[i]);
		}

		int cnt = 0;
		for(int i=0;i<n;i++) {
			if(str[i] == '1') cnt++;
		}

		printf("%d\n", cnt - ans);
	}
}