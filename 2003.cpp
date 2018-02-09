//2003.cpp
#include <cstdio>

int a[10001];
int main(){
	int n, s; scanf("%d %d", &n, &s);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);

	int start = 1, end = 1, ans = 0, sum = 0;
	for(int i=1;i<=n;i++){
		sum += a[i];
		if(sum == s) ans++;

		while(s <= sum){
			sum -= a[start];
			start++;
			if(sum == s) ans++;
		}
	}	
	printf("%d", ans);
}
