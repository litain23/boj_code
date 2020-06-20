#include <iostream>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, k;
		scanf("%d %d", &n, &k);

		string str;
		cin >> str;

		int lastIndex = -1;
		int ans = 0;
		for(int i=0;i<n;i++) {
			char c = str[i];
			if(c == '1') {
				if(i - lastIndex <= k && lastIndex != -1) {
					ans--;
				}

				lastIndex = i;
			} else {
				if(lastIndex == -1 || i - lastIndex > k) {
					lastIndex = i;
					ans++;
				}
			}
		}

		cout << ans << "\n";

	}
}