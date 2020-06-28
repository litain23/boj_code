#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		string str;
		cin >> str;

		int zeroCnt = 0, oneCnt = 0;
		for(char c : str) {
			if(c == '0') zeroCnt++;
			else oneCnt++;
		}

		int mn = zeroCnt < oneCnt ? zeroCnt : oneCnt;
		if(mn % 2) {
			printf("DA\n");
		} else {
			printf("NET\n");
		}
	}
}