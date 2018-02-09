//13470.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[101], B[101];
vector<pair<int, int>> stu_addr, teach_addr;
vector<int> v[101];
bool visited[101];

int abs(int x){ return x > 0? x : -x;}
int dist(pair<int,int> x, pair<int, int> y){
	return abs(x.first-y.first) + abs(x.second-y.second);
}

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
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x, y; scanf("%d %d", &x, &y);
		stu_addr.push_back(make_pair(x, y));
	}		
	for(int i=0;i<n;i++){
		int x, y; scanf("%d %d", &x, &y);
		teach_addr.push_back(make_pair(x, y));
	}		

	int start = -1, end = 4e8+1, mid;
	while(start + 1 < end){
		mid = (start + end)/2;
		for(int i=0;i<100;i++) v[i].clear();

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist(stu_addr[i], teach_addr[j]) <= mid) v[i].push_back(j);
			}
		}

		int match = 0;
		fill(A, A+100, -1);
		fill(B, B+100, -1);
		for(int i=0;i<n;i++){
			if(A[i] == -1){
				fill(visited, visited+100, false);
				if(dfs(i)) match++;
			}
		}
		if(match == n) end = mid;
		else start = mid;
	}

	printf("%d", end);
}