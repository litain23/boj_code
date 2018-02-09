//2533.cpp
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


const int INF = 0x3f3f3f3f;
vector<int> v[1000001];
int d[1000001][2];


int f(int x, int prev, bool selected){
	if(d[x][selected] != INF) return d[x][selected];
	d[x][selected] = 0;
	
	for(int i : v[x]){
		if(i == prev) continue;
		if(selected){
			d[x][selected] += (min(f(i, x, false), f(i, x, true)));
		} else{
			d[x][selected] += f(i, x, true);
		}
	}

	if(selected) d[x][selected]++;
	return d[x][selected];
}

int main(){
	memset(d, 0x3f, sizeof(d));
	int n; scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		int s, e; scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}

	printf("%d", min(f(1, 0, true), f(1, 0, false)));
}