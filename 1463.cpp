//1463.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[1000001];

int f(int x){
	if(d[x] != 0x3f3f3f3f) return d[x];
	if(x <= 1) return 0;

	d[x] = f(x-1);
	if(x % 3 == 0) d[x] = min(d[x], f(x/3));
	if(x % 2 == 0) d[x] = min(d[x], f(x/2));

	d[x]++;

	return d[x];
}

int main(){
	int n; scanf("%d", &n);
	memset(d, 0x3f, sizeof(d));

	printf("%d", f(n));
}