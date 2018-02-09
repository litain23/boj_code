//1655.cpp
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> mxq;
priority_queue<int, vector<int>, greater<int>> mnq;
int main(){
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t; scanf("%d", &t);

		if(mxq.empty()) mxq.push(t);
		else if(t < mxq.top()){
			mnq.push(mxq.top());
			mxq.pop();
			mxq.push(t);		
		}
		else mnq.push(t);

		while(mnq.size() > mxq.size()){
			mxq.push(mnq.top()); mnq.pop();
		}

		printf("%d\n", mxq.top());
	}
}
