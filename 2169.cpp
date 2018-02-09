//2169.cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1002][1002], d[1002][1002], dright[1002][1002], dleft[1002][1002];
int n, m;
void f(int x){
	for(int i=1;i<=m;i++){
		if(d[x][i-1] == -987654321) dright[x][i] = d[x-1][i] + a[x][i];
		else dright[x][i] = a[x][i] + max(d[x-1][i], dright[x][i-1]);
	}

	for(int i=m;i>=1;i--){
		if(d[x][i+1] == -987654321) dleft[x][i] = d[x-1][i] + a[x][i];
		else dleft[x][i] = a[x][i] + max(d[x-1][i], dleft[x][i+1]);
	}

	for(int i=1;i<=m;i++) d[x][i] = max(dright[x][i], dleft[x][i]);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			d[i][j] = -987654321;
			dright[i][j] = -987654321;
			dleft[i][j] = -987654321;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d", &a[i][j]);
			d[i][j] = 0;
		}
	}
	d[1][0] = 0;
	for(int i=1;i<=m;i++) d[1][i] = (d[1][i-1] + a[1][i]);

	for(int i=2;i<=n;i++) f(i);
	printf("%d\n", d[n][m]);
}