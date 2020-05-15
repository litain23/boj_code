#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int a[200001];

struct info{
	int start, end;

	info(int s, int e) : start(s), end(e) {}
};

struct cmp {
	bool operator() (const info & lh, const info& rh) {
		int lhDiff = lh.end - lh.start;
		int rhDiff = rh.end - rh.start;
		if(lhDiff == rhDiff) {
			return lh.start > rh.start;
		} else {
			return lhDiff < rhDiff;
		}
	}
};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		priority_queue<info, vector<info>, cmp> pq;
		memset(a, 0, sizeof(a));
		int cnt = 1;
		int n; scanf("%d", &n);
		pq.push(info(1, n));
		while(!pq.empty()) {
			info x = pq.top(); pq.pop();
			if(x.start == x.end) {
				a[x.start] = cnt++;
				continue;
			}

			// printf("%d %d\n", x.start, x.end);
			int diff = x.end - x.start + 1;

			if(diff % 2) {
			// 길이가 홀수다 아주좋음 절반 나눠먹으면됨
				int mid = (x.start + x.end) / 2;
				a[mid] = cnt++;
				pq.push(info(x.start, mid-1));
				pq.push(info(mid+1, x.end));
			} else {
			// 길이다 짝수다 .. 
				int mid = (x.start + x.end - 1) / 2;
				a[mid] = cnt++;
				if(mid - 1 >= x.start) {
					pq.push(info(x.start, mid-1));

				}

				if(mid + 1 > x.end) continue;
				else pq.push(info(mid+1, x.end));
			}
		}
		for(int i=1;i<=n;i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
}