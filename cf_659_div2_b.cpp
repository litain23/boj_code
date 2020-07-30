#include <iostream>
#include <vector>
#include <string>	
#include <algorithm>
#include <queue>
using namespace std;

struct info{
	char start, end;

	info(char s, char e) {
		start = s;
		end = e;
	}

	bool operator < (const info& rhs) const {
		if(start == rhs.start) {
			return end > rhs.end;
		}
		return start > rhs.start;
	}
};

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string a, b;
		cin >> a >> b;

		bool hanAns = true;
		for(int i=0;i<n;i++) {
			if(a[i] > b[i]) {
				hanAns = false;
				break;
			}
		}

		if(!hanAns) {
			printf("-1\n");
			continue;
		}
		int cnt = 0;
		priority_queue<info> pq;

		for(int i=0;i<n;i++) {
			if(a[i] == b[i]) continue;
			pq.push(info(a[i], b[i]));
		}

		while(!pq.empty()) {
			info here = pq.top(); pq.pop();
			vector<info> acc;
			while(!pq.empty() && pq.top().start == here.start) {
				if(here.end == pq.top().end) pq.pop();
				else {
					acc.push_back(info(here.end, pq.top().end));
					pq.pop();
				}
			}

			for(info i : acc) {
				pq.push(i);
			}
			cnt++;
		}

		cout << cnt << "\n";
	}	
}