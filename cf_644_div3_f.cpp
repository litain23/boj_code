#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;

		string str[10];

		for(int i=0;i<n;i++) {
			cin >> str[i];
		}


		bool hasAns = false;
		if(m >= 3) {
			int minusCnt = 2;

			int alphabetCnt[10][26];
			for(int i=0;i<m;j++) {
				for(int j=0;j<n;j++) {
					alphabetCnt[i][str[j][i] - 'a']++;	
				}
			}

			for(int i=0;i<26;i++) {
				for(int j=0;j<m;j++) {
					alphabetCnt[j][i]
				}
			}





		} else if(m == 2) {
			for(int i=0;i<26;i++) {
				char c = 'a' + i;
				int cnt = 0;
				for(int j=0;j<n;j++) {
					if(str[j][0] == c || str[j][1] == c) {
						cnt++;
					}
				}

				if(cnt == n) {
					printf("%c%c\n", c, c);
					hasAns = true;
					break;
				}
			}

			if(!hasAns) {
				printf("-1\n");
			}
		} else {
			printf("z\n");
		}
	}	
}