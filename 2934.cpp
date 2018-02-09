#include <cstdio>

int fenwick[100003];
int get(int p){
	int ret = 0;
	for(int i=p;i>0;i-=(i&-i)) ret += fenwick[i];
	return ret;
}

void update(int p, int v){
	for(int i=p;i<=100000;i+=(i & -i)) fenwick[i] += v;
}

int main(){
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i=0;i<n;i++){
		int s, e; scanf("%d %d", &s, &e);
		int v1 = get(s), v2 = get(e);
		printf("%d\n", v1 + v2);
		update(s, -v1); update(s + 1, v1);
		update(e, -v2); update(e + 1, v2);
		update(s+1, 1); update(e, -1);				
	}
}