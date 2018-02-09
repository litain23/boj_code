//1012.cpp
#include <cstdio>
#include <cstring>
using namespace std;


int a[51][51], ck[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n, m;

void dfs(int x, int y){
	ck[x][y] = true;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ck[nx][ny]) continue;
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(a[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}
int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		memset(a, 0, sizeof(a));
		memset(ck, 0, sizeof(ck));
		int k, ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0;i<k;i++){
			int x, y; scanf("%d %d", &x, &y);
			a[x+1][y+1] = 1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				//printf("%d ", a[i][j]);
			}
			// puts("");
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j] == 0 || ck[i][j]) continue;
				dfs(i, j);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}