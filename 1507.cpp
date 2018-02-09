//1507.cpp
#include <cstdio>

int a[21][21], chk[21][21];
int main(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i == k) continue;
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				if(j == k) continue;
				if(a[i][k] + a[k][j] == a[i][j]) chk[i][j] = true;
				else if(a[i][k] + a[k][j] < a[i][j]) return !printf("-1");
			}
		}
	}	
	int sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(chk[i][j]) continue;
			sum += a[i][j];
		}
	}
	printf("%d", sum / 2);
}
