#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main() {
	int n, m, sx, sy;
	cin >> n >> m >> sx >> sy;

	vector<pair<int,int>> v;
	
	v.push_back(make_pair(sx, sy));
	v.push_back(make_pair(1, sy));
	v.push_back(make_pair(1, 1));

	int nx = 1;
	int ny = 1;

	int direct = 0;
	while(1) {
		if(v.size() == n * m) {
			break;
		}

		nx += dx[direct];
		ny += dy[direct];

		if(direct == 3) {
			if(ny == m) {
				direct = 1;
			} else {
				direct = 0;
			}
		} else if(ny == m || ny == 1) {
			direct = 3;
		}

		if(nx == sx && ny == sy) {
			continue;
		} else if(nx == 1 && ny == sy) {
			continue;
		}

		v.push_back(make_pair(nx, ny));

	}

	for(auto i : v) {
		printf("%d %d\n", i.first, i.second);
	}


}