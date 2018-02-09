#include <cstdio>

int main(){
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);

	int ans = (v - a) / (a-b);

	if((v - a) % (a-b) != 0){
		ans++;
	}
	printf("%d", ans+1);
}