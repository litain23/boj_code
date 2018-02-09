#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5 + 9; 

int f[MAX_N];
 
int get(int p){
	int res = 0;
	for(int i = p + 1; i; i -= (i & -i)) res += f[i];
	return res;
}

void update(int p, int v){
	for(int i = p + 1; i < MAX_N; i += (i & -i)) f[i] += v;
}  

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b, v;
		cin >> a >> b >> v;
		update(a, v);
		update(b + 1, -v);
	}
	int m;
	cin >> m;
	while(m--){
		int v;
		cin >> v;
		printf("%d\n", get(v));
	}
}