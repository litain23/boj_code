//3013.cpp
#include <cstdio>
#include <map>
using namespace std;

int a[100001];
map<int, int> left, right;
int main(){
	int n, b, start; scanf("%d %d", &n, &b);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);		
		if(a[i] == b) start = i;
	}

	int cnt = 0, ans = 0;
	for(int i=start-1;i>0;i--){
		if(a[i] < b) cnt--;
		else cnt++;
		left[cnt]++;
	}
	cnt = 0;
	for(int i=start+1;i<=n;i++){
		if(a[i] < b) cnt--;
		else cnt++;
		ans += left[-cnt];
		if(cnt == 0) ans++;
	}

	printf("%d", ans + left[0] + 1);
}
