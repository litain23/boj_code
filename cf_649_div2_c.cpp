#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a[100001];
int main() {
	int n; cin >> n;
	bool hasAns = true;
	int minAcc = 100000;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if(i < a[i]) hasAns = false;
		minAcc = min(minAcc, i - a[i]);
	}	

	if(!hasAns) return 0 & printf("-1");
	vector<int> ans;

	queue<int> emptyNumber;
	for(int i=2;i<=n;i++) {
		for(int j=a[i-1]+1;j<a[i];j++) {
			emptyNumber.push(j);
		}	
	}

	bool isZeroIn = false;
	for(int i=1;i<=n;i++) {
		if(a[i] == 0) {
			if(!emptyNumber.empty()) {
				ans.push_back(empty.front());
				emptyNumber.pop();
			} else {
				ans.push_back(100001);
			}
		} else {
			if(!isZeroIn) ans.push_back(0);
			else {
				
			}
		}

	}	
}
