//2616.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int a[50001], d[50001][4], sum[50001];
int n, m;

int f(int x, int remain){
	if(x + m - 1 > n) return 0;
	if(d[x][remain]) return d[x][remain];
	if(remain == 0) return 0;

	int partial_sum = sum[min(x+m, n+1)-1] - sum[x-1];
	d[x][remain] = max(partial_sum + f(x+m, remain-1), f(x+1, remain));

	return d[x][remain];
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		sum[i] += (sum[i-1] + a[i]);
	}
	scanf("%d", &m);
	printf("%d", f(1, 3));	
}
	