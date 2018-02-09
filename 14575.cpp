//14575.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
int main(){
	int n, total; scanf("%d %d", &n, &total);
	int ans = 1e6+9;
	for(int i=0;i<n;i++){
		int s, e; scanf("%d %d", &s, &e);
		v.push_back(make_pair(s, e));
		ans = min(ans, s);
	}

							
}