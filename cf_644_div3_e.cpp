#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str[50];
		int n; scanf("%d", &n);
		for(int i=0;i<n;i++) {
			cin >> str[i];
		}

		if(n == 1) {
			printf("YES\n");
			continue;
		}

		bool hasAns = true;
		for(int i=n-2;i>=0;i--) {
			for(int j=i;j>=0;j--) {
				if(str[i][j] == '1') {
					if( !(str[i+1][j] == '1' || str[i][j+1] == '1')) {
						hasAns = false;
						break;
					}
				}

				if(str[j][i] == '1') {
					if( !(str[j+1][i] == '1' || str[j][i+1] == '1')) {
						hasAns = false;
						break;
					}
				}				
			}

			if(!hasAns) break;
		}

		printf("%s\n", hasAns ? "YES" : "NO");
	}
}