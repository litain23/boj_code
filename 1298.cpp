//1298.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 101;

int A[MAX_N], B[MAX_N];
bool visited[MAX_N];
vector<int> v[MAX_N];

bool dfs(int a){
	visited[a] = true;
	for(int b : v[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}


int main(){
	int n, m; scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		int s, e; scanf("%d %d", &s, &e);
		v[s].push_back(e);
	}	

	int ans = 0;
	fill(A, A+MAX_N, -1);
	fill(B, B+MAX_N, -1);
	for(int i=1;i<=100;i++){
		if(A[i] == -1){
			fill(visited, visited+MAX_N, false);
			if(dfs(i)) ans++;
		}
	}
	printf("%d", ans);
}