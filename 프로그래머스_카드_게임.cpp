#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42896
*/

vector<int> lh, rh;
int d[2001][2001];

int f(int x, int y) {
    if(x >= lh.size() || y >= lh.size()) return 0;
    if(d[x][y] != -1) return d[x][y];
    
    if(rh[y] < lh[x]) {
        d[x][y] = f(x, y+1) + rh[y];
    } else {
        d[x][y] = max(f(x+1, y), f(x+1, y+1));
    }
    return d[x][y];
}

int solution(vector<int> l, vector<int> r) {
    lh = l;
    rh = r;
    memset(d, -1, sizeof(d));
    return f(0, 0);
}