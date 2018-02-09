//2231.cpp
#include <cstdio>

int f(int n){
	int ret = 0;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++){
		if(i + f(i) == n){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}