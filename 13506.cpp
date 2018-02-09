//13506.cpp
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, L, temp[1000001];
vector<int> z(1000001);
int main(){
	string a;
	cin >> a;
	int n = a.size();
	z.resize(n);
	for(int i=1;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && a[R-L] == a[R]) R++;
			z[i] = R - L; R--;
		}
		else{
			int k = i - L;
			if(z[k] < R - i + 1) z[i] = z[k];
			else{
				L = i;
				while(R < n && a[R-L] == a[R]) R++;
				z[i] = R - L; R--;
			}
		}
	}


	bool ck = false;
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
		if(z[i] != 0) ck = true;
		if(ck){
			if(!ans.empty() && ans.back() >= n-i) break;
			if(z[i] == n-i) ans.push_back(n-i);

		}
	}	

	if(ans.empty()){
		printf("-1");
		return 0;
	}
	sort(z.begin(), z.end());
	for(int i = ans.size()-1; i>=0;i--){
		auto it = lower_bound(z.begin(), z.end(), ans[i]);
		int x = z.end() - it;
		if(x >= 2) {
			cout << ans[i] << '\n';
		}
	}
	printf("-1");
}
