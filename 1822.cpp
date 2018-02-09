//1822.cpp
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<int, int> mp;
vector<int> ans;
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		int t; scanf("%d", &t);
		mp[t]++;
	}
	for(int i=0;i<m;i++){
		int t; scanf("%d", &t);
		if(mp[t]) mp[t] = 0;
	}

	for(auto i : mp){
		for(int j=0;j<i.second;j++){
			ans.push_back(i.first);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i : ans) printf("%d ", i);
}