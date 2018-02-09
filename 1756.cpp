//1756.cpp
#include <cstdio>
#include <stack>
using namespace std;


int oven[300001];
stack<int> st;
int main(){
	int n, d; scanf("%d %d", &d, &n);
	oven[0] = 1e9+9;
	for(int i=1;i<=d;i++) {
		int t; scanf("%d", &t);
		if(t < oven[i-1]) oven[i] = t;
		else oven[i] = oven[i-1];
	}

	for(int i=1;i<=d;i++) st.push(oven[i]);
	for(int i=0;i<n;i++){
		int t; scanf("%d", &t);
		while(!st.empty() && st.top() < t) st.pop();

		if(!st.empty()) st.pop();
		else{
			printf("0");
			return 0;
		}
	}
	printf("%d", st.size()+1);
}