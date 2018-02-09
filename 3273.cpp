//3273.cpp
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map<int, int> mp;
vector<int> v;
int main(){
	int n, s; scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t; scanf("%d", &t);
		v.push_back(t);
		mp[t]++;
	}

	scanf("%d", &s);
	int ans = 0;
	for(int i : v){
		if(mp[s- i]) ans++;
	}
	printf("%d", ans/2);
}