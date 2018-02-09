//2343.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100001], n, m;
int main(){
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);	
	}
	int start = *max_element(a + 1, a + n + 1) -1, end = 1e9+1, mid = 0;
	while(start + 1 < end){
		mid = (start+end)/2;
		int cnt = 1;

		int sum = 0;
		for(int i=1;i<=n;i++){
			sum += a[i];
			if(sum > mid) {
				cnt++;
				sum = a[i];
			}
		}
		if(cnt <= m) end = mid;
		else start = mid;
	}
	printf("%d", end);
}