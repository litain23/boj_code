//13576.cpp
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int R, L, p[1000001], cnt[1000001];
vector<int> z;
vector<pair<int, int> > ans;
int main(){
	string str; 
	cin >> str;
	int n = str.size();
	z.resize(n);
	for(int i=1;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && str[R-L] == str[R]) R++;
			z[i] = R - L; R--;
		}
		else{
			int k = i - L;
			if(z[k] < R - i + 1) z[i] = z[k];
			else{
				L = i;
				while(R < n && str[R-L] == str[R]) R++;
				z[i] = R - L; R--;
			}
		}
	}

	for(int i : z) cnt[i]++;
	p[0] = cnt[0];
	for(int i=1;i<n;i++) p[i] = cnt[i] + p[i-1]; 

	for(int i=n-1;i>=0;i--){
		if(z[i] + i == n){
			ans.push_back(make_pair(z[i], n - p[z[i]-1] + 1));
		}
	}
	ans.push_back(make_pair(n, 1));
	printf("%d\n", ans.size());
	for(auto i : ans){
		printf("%d %d\n", i.first, i.second);
	}

}
