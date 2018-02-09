#include <bits/stdc++.h>

using namespace std;

int main(){ 
	int l = 0, r = 10;
	while(l + 1 < r){
		int m = (l + r) / 2;
		if(condition(m)) l = m;
		else r = m;
	}
	printf("%d", l);
}