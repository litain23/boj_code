//2213.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int w[10001], d[10001][2];
vector<int> path;

int f(int x, int selected, int prev){
	if(d[x][selected]) return d[x][selected];

	for(int i : v[x]){
		if(i == prev) continue;

		if(selected) d[x][selected] += f(i, 0, x);
		else d[x][selected] += max(f(i, 0, x), f(i, 1, x));
	}

	if(selected) d[x][selected] += w[x];
	return d[x][selected];
}


void trace(int x, int selected, int prev){
	if(selected){
		path.push_back(x);
		for(int i : v[x]){
			if(i == prev) continue;
			trace(i, 0, x);
		}
	} else{
		for(int i : v[x]){
			if(i == prev) continue;

			if(d[i][1] > d[i][0]) trace(i, 1, x);
			else trace(i, 0, x);
		}
	}
}

int main(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &w[i]);

	for(int i=1;i<n;i++){
		int s, e; scanf("%d %d", &s, &e);
		v[s].push_back(e);		
		v[e].push_back(s);		
	}

	int ans1 = f(1, 0, 0);
	int ans2 = f(1, 1, 0) ;
	if(ans1 < ans2) trace(1, 1, 0);
	else trace(1, 0, 0);

	printf("%d\n", max(ans1, ans2));
	sort(path.begin(), path.end());
	for(int i : path) printf("%d ", i);

}