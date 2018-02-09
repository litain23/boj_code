//1758.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100001];
int main(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}	

	long long ans = 0LL;
	sort(a+1, a+n+1);
	for(int i=n;i>=0;i--){
		if(a[i] - (n-i+1) + 1 > 0) ans += (a[i] - (n-i+1) + 1);
	}
	printf("%lld", ans);

}