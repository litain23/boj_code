#include <cstdio>

const int MOD = 100999;
int d[2001][2001], n;

int f(int x, int y){
	if(d[x][y]) return d[x][y];
	if(x < y) return 0;
	if(x < 0 || y < 0 || x > 2000 || y > 2000) return 0;

	d[x][y] = (f(x - y, y + 1) + f(x, y + 1))%MOD;
	return d[x][y];
}

int main(){
	for(int i=1;i<=2000;i++) d[i][i] = 1; 
	int tc; scanf("%d", &tc);
	while(tc--){
		int ans = 0;
		scanf("%d", &n);
		printf("%d\n", f(n, 1));
	}
}
