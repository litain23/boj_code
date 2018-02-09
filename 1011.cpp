//1011.cpp
#include <cstdio>
#include <cmath>
using namespace std;

long long f(long long x){
	if(x == 2) return 2LL;
	long long ans = sqrt(x);
	if(ans*ans == x) return ans*2-1;
	else{
		if(x < ans*ans + ans + 1LL) return ans*2;
		else return ans*2+1;
	}
}

int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", f(y - x));	
	}
}