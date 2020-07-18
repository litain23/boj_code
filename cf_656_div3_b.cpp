#include <iostream>
#include <cstring>
using namespace std;

int a[1001];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		memset(a, 0, sizeof(a));
		int n; cin >> n;
		for(int i=1;i<=2*n;i++) {
			int t;
			scanf("%d", &t);
			a[t]++;
			if(a[t] == 1) {
				printf("%d ", t);
			}
		}

		puts("");
	}	
}