//1208.cpp
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v, sum_v1, sum_v2;
void f(vector<int> &sum1, vector<int> &vv, int i, int sum){
	if(i == vv.size()){
		sum1.push_back(sum);
		return;
	}
	f(sum1, vv, i+1, sum);
	f(sum1, vv, i+1, sum+vv[i]);
}

int main(){
	int n, s;
	long long ans = 0;
	scanf("%d %d", &n, &s);
	v.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	vector<int> v1(v.begin(), v.begin() + n/2);
	vector<int> v2(v.begin() + n/2, v.end());

	f(sum_v1, v1, 0, 0);
	f(sum_v2, v2, 0, 0);

	sort(sum_v1.begin(), sum_v1.end());

	for(int i : sum_v2){
		int find_value = s - i;
		auto it1 = lower_bound(sum_v1.begin(), sum_v1.end(), find_value);
		auto it2 = upper_bound(sum_v1.begin(), sum_v1.end(), find_value);
		ans = ans + it2 - it1;
	}
	if(s == 0) ans--;
	printf("%lld", ans);

}