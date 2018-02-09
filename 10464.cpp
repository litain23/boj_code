//10464.cpp
#include <cstdio>


int a[31];

int f1(int x){
	for(int i=0;i<=30;i++) if(x < 1<<i) return i;
}

int f2(int x){
	for(int i=30;i>=0;i--) if(x > 1<<i) return i;
}

int main(){
	int tc;	scanf("%d", &tc);
	for(int i=1;i<=30;i++) a[i] = 1<<i;
	while(tc--){
		int a, b; scanf("%d %d", &a, &b);
		int mn = f1(a);		
		int mx = f2(b);
		//if mx == mn 일때 고려 필요
		int ans = 0;

		if(a%2){
			if(((1 << mn) - a + 1)/2%2 == 1) ans = a - 1;
			else ans = a;
		} else{
			if(((1 << mn) - a + 1)/2%2 == 1) ans = 1;
			else ans = 0;
		}

		if(b%2){
			
		} else{

		}


	}
}