//1813.cpp
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int a[100001];
map<int, int> mp;
int main(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		mp[a[i]]++;		
	}
	int mx = -1;
	for(int i=1;i<=n;i++){
		if(mp[a[i]] == a[i]) mx = max(mx, a[i]);
	}
	if(mx == -1 && mp[0] > 0) printf("-1");
	else if(mx == -1) printf("0");
	else printf("%d", mx);	
}
