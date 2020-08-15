#include <iostream>
#include <algorithm>
using namespace std;

bool f(int arr[4]) {
	int oddCnt = 0;
	int eventCnt = 0;

	for(int i=0;i<4;i++) {
		if(arr[i] % 2) {
			oddCnt++;
		} else {
			eventCnt++;
		}
	}
	if(oddCnt == 1 && eventCnt == 3) {
		return true;
	} else if(eventCnt == 4) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int arr[4];
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

		if(f(arr)) {
			printf("Yes\n");
			continue;
		}

		bool hasAns = true;
		for(int i=0;i<3;i++) {
			if(arr[i] == 0) {
				hasAns = false;
			} else {
				arr[i]--;
			}
		}

		arr[3] += 3;

		if(!hasAns || !f(arr)) {
			printf("No\n");
			continue;
		}

		if(f(arr)) {
			printf("Yes\n");
			continue;
		}

		int mn = 1e9+1;
		for(int i=0;i<3;i++) {
			mn = min(arr[i], mn);
		}

		for(int i=0;i<3;i++) {
			arr[i] -= mn;
		}
		arr[3] += mn * 3;

		if(f(arr)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}



	}
}