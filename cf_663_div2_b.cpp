#include <iostream>
#include <string>
using namespace std;


int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m;
		scanf("%d %d", &n, &m);

		string str[100];
		for(int i=0;i<n;i++) {
			cin >> str[i];
		}

		int cnt = 0;
		for(int i=0;i<n;i++) {
			if(str[i][m-1] == 'R') cnt++;
		}
		for(int i=0;i<m;i++) {
			if(str[n-1][i] == 'D') cnt++;
		}
		printf("%d\n", cnt);
	}	
}