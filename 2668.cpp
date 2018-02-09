//2668.cpp
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a[101], ck[101];
queue<int> que;

int main(){
	int n;
	vector<int> ans;
	scanf("%d", &n);
	int total = n;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		ck[a[i]]++;
	}

	for(int i=1;i<=n;i++){
		if(ck[i] == 0) que.push(i), total--;
	}

	while(!que.empty()){
		int x = que.front();
		que.pop();

		ck[a[x]]--;
		if(ck[a[x]] == 0){
			que.push(a[x]);
			total--;
		}
	}

	printf("%d\n", total);
	for(int i=1;i<=n;i++){
		if(ck[i]) printf("%d\n", i);
	}
}