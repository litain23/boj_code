//1939.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,int>> v[10001];
bool ck[10001];

bool hasAns;
void dfs(int x, int end, int value){
	ck[x] = true;
	for(auto i : v[x]){

		if(ck[i.first]) continue;
		if(i.second < value) continue;
		if(i.first == end) hasAns = true;
		dfs(i.first, end, value);
	}
}
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		v[s].push_back(make_pair(e, w));
		v[e].push_back(make_pair(s, w));
	}	

	int s, e; scanf("%d %d", &s, &e);
	int start = 0, end = 1e9+1, mid = 0;
	while(start + 1 < end){
		memset(ck, 0, sizeof(ck));
		mid = (start+end)/2;
		hasAns = false;
		dfs(s, e, mid);
		if(hasAns) start = mid;
		else end = mid;
	}

	printf("%d", start);
}