#include <cstdio>

const int MOD = 45678;

int main(){
	int n; scanf("%d", &n);
	int	ans = 5; 
	for(int i=2;i<=n;i++){
		ans += 3 * i + 1;
		ans %= MOD;
	}
	printf("%d", ans);
}