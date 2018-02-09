//2697.cpp
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int cnt[10], a[81];
int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		string str; cin >> str;
		int n = str.size();
		for(int i=0;i<10;i++) cnt[i] = 0;
		for(int i=0;i<81;i++) a[i] = 0;
		for(int i=0;i<n;i++) a[i] = str[i]-'0';


		int mx = 0;
		bool hasAns = false;

		for(int i=n-1;i>=0;i--){
			cnt[a[i]]++;
			if(mx <= a[i]) mx = a[i];
			else{
				hasAns = true;
				for(int j=0;j<i;j++) printf("%d", a[j]);
				for(int j=0;j<10;j++){
					if(a[i] < j && cnt[j]){
						printf("%d", j);
						cnt[j]--;
						break;
					}
				}
				for(int j=0;j<10;j++){
					while(cnt[j] > 0){
						printf("%d", j);
						cnt[j]--;
					}
				}

				break;
			}
		}
		if(!hasAns) printf("BIGGEST\n");
		else puts("");

	}
}