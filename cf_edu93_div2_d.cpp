#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> r, g, b;

int d[201][201][201];

int f(int x, int y, int z) {
	if( (x < 1 && y < 1) ||
		(y < 1 && z < 1) || 
		(z < 1 && x < 1) ){
		return 0;
	}
	if(d[x][y][z] != -1) return d[x][y][z];
	if(x < 1) {
		d[x][y][z] = g[y-1] * b[z-1] + f(x, y-1, z-1);	
	} else if(y < 1) {
		d[x][y][z] =  r[x-1] * b[z-1] + f(x-1, y, z-1);	
	} else if(z < 1) {
		d[x][y][z] = r[x-1] * g[y-1] + f(x-1, y-1, z);	
	} else {
		d[x][y][z] = max({
			r[x-1] * g[y-1] + f(x-1, y-1, z), 
			r[x-1] * b[z-1] + f(x-1, y, z-1), 
			g[y-1] * b[z-1] + f(x, y-1, z-1)
		});
	}

	return d[x][y][z];
}
int main() {
	int red, green, blue;
	cin >> red >> green >> blue;

	for(int i=0;i<red;i++) {
		int t; scanf("%d", &t);
		r.push_back(t);
	}
	for(int i=0;i<green;i++) {
		int t; scanf("%d", &t);
		g.push_back(t);
	}
	for(int i=0;i<blue;i++) {
		int t; scanf("%d", &t);
		b.push_back(t);
	}

	memset(d, -1, sizeof(d));
	sort(r.begin(), r.end());
	sort(g.begin(), g.end());
	sort(b.begin(), b.end());

	cout << f(red, green, blue);
}