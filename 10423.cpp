//10423.cpp
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	for(int i=0;i<m;i++){
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		v[s].push_back(make_pair(e, w));
		v[e].push_back(make_pair(s, w));
	}	
}
