//1004.cpp
#include <cstdio>

bool in_planet(int x1, int y1, int x2, int y2, int r){
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) < r*r;
}

int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		int x1, y1, x2, y2, ans = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int n; scanf("%d", &n);
		for(int i=0;i<n;i++){
			int x, y, r; scanf("%d %d %d", &x, &y, &r);
			if(in_planet(x1, y1, x, y, r)^in_planet(x2, y2, x, y, r)) ans++;
		}				
		printf("%d\n", ans);
	}
}