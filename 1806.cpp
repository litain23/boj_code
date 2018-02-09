//1806.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005], sum[100005];

int main(){
	int n, s; scanf("%d %d", &n, &s);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		sum[i] += (sum[i-1] + a[i]);
	}

	int start = 0, ans = 1e9+1;
	for(int i=1;i<=n;i++){
		while(s <= sum[i] - sum[start]){
			ans = min(ans, i - start);
			start++;
		}
	}
	if(ans == 1e9 + 1) printf("0");
	else printf("%d", ans);
}