//11046.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int a[2000005];
int main(){
	int n; scanf("%d", &n);
	v.resize(n*2+1);
	v[0] = -1;
	for(int i=1;i<n*2+1;i++){
		if(i%2 == 1) scanf("%d", &v[i]);
		else v[i] = -1;
	}

	int L = 0, R = 0;
	for(int i=1;i<n*2+1;i++){
		if( R < i ){
			L = R = i;
			int t = 1;
			while( i-t >= 0 && i+t < 2*n+1 && v[i-t] == v[i+t]) R++, t++;
			a[i] = R-L, R--;
		} else{
			int k = 2*L - i;
			if(2*n-1 - i < a[k]) a[i] = 2*n-1 -i;
			else if(a[k] < R - i + 1) a[i] = a[k];
			else{
				L = i;
				int t = R-L+1;
				while( i-t >= 0 && i+t < 2*n+1 && v[i-t] == v[i+t]) R++, t++;
				a[i] = R-L; R--;
			}
		}
	}
	int m; scanf("%d", &m);
	for(int i=0;i<m;i++){
		int s, e; scanf("%d %d", &s, &e);
		int ss = s*2-1, ee = e*2-1;
		if(ss > ee) swap(ss, ee);
		if(a[(ee + ss) / 2] >= (ee - ss) / 2) printf("1\n");
		else printf("0\n");
	}
 }