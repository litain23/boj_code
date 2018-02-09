//2539.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main(){
	int n, m, s, k, mx = 0;
	scanf("%d %d %d %d", &n, &m, &s, &k);
	for(int i=0;i<k;i++){
		int x, y; scanf("%d %d", &x, &y);
		mx = max(mx, x);
		v.push_back(y);
	}	

	sort(v.begin(), v.end());

	int start = mx - 1, end = 1e6+1, mid = 0;
	while(start + 1 < end){
		mid = (start + end)/2;
		int cnt = 1;
		int current_x = v[0] - 1;

		for(int i : v){
			if(i - current_x <= mid) continue;
			else{
				current_x = i - 1;
				cnt++;
			}
		}

		if(cnt <= s) end = mid;
		else start = mid;
	}

	printf("%d", end);
}
