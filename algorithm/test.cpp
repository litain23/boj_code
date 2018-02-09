#include <stdio.h>
#include <queue>
#include <functional>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
vector<pair<int, int>> v;
int main(){
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x, y; scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), [](pair<int, int> i, pair<int,int> j){
		if(i.first == j.first) return i.second < j.second;
		return i.first < j.first;
	});

	for(auto i : v){
		printf("%d %d\n", i.first, i.second);
	}


}
