//9426.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int fenwick[66000], a[250001];
void update(int p, int v){
	p++;
	while(p < (1<<16) + 9){
		fenwick[p] += v;
		p += (p & -p);
	}
}

int query(int p){
	p++;
	int ret = 0;
	while(p > 0){
		ret += fenwick[p];
		p -= (p & -p);
	}
	return ret;
}

int binary_S(int k){
	int start = -1, end = (1<<16) + 1, mid;	
	while(start + 1 < end){
		int find = k;
		mid = (start+end)/2;
		int value = query(mid);
		if(value < find) start = mid;
		else end = mid;
	}
	return end;
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<k;i++) update(a[i], 1);


	long long ans = binary_S((k+1)/2);
	for(int i=k;i<n;i++){
		update(a[i-k], -1);
		update(a[i], 1);
		ans += binary_S((k+1)/2);
	}
	printf("%lld", ans);
}