#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int PILLAR = 0;
const int BO = 1;
// 기둥의 위치 : [x][y] 면 기둥은 x 위로 한칸 기둥
bool pillar[105][105];
// 보의 위치 : [x][y] 면 보는 [x][y] 와 [x][y+1] 까지 있음
bool bo[105][105];
int n;

bool canBuildPillar(int x, int y) {
    bool isOk = false;
    if(y == 0) {
        isOk = true;
    } else {
        if(pillar[x][y-1]) {
            isOk = true;
        } else if(x != 0 && bo[x-1][y]) {
            isOk = true;
        } else if(bo[x][y]) {
            isOk = true;
        }
    }

    return isOk;
}

bool canBuildBo(int x, int y) {
    bool isOk = false;
    if(y == 0) return false;

    if(pillar[x][y-1]) {
        isOk = true;
    } else if(x != n && pillar[x+1][y-1]) {
        isOk = true;
    } else if(x != 0 && bo[x-1][y] && bo[x+1][y]) {
        isOk = true;
    }
    return isOk;
}

bool erases() {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(pillar[i][j]) {
                if(!canBuildPillar(i, j)) {
                    return false;
                }
            } 

            if(bo[i][j]) {
                if(!canBuildBo(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}
vector<vector<int>> solution(int nn, vector<vector<int>> build_frames) {
    vector<vector<int>> ans;
    n = nn; 
    for(vector<int> frame : build_frames) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];
        
        if(b == 1) {
            if(a == BO && canBuildBo(x, y)) {
                bo[x][y] = true;
            } else if(a == PILLAR && canBuildPillar(x, y)) {
                pillar[x][y] = true; 
            }
        } else {
            if(a == BO) {
                bo[x][y] = false;
            } else {
                pillar[x][y] = false;
            }
            if(!erases()) {
               if(a == BO) {
                    bo[x][y] = true;
                } else {
                    pillar[x][y] = true;
                } 
            }
        }
    }
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(pillar[i][j]) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(PILLAR);
                ans.push_back(v);
            }

            if(bo[i][j]) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(BO);
                ans.push_back(v);
            }
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> x = {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
    int n = 5;
    for(vector<int> i : solution(n , x)) {
        printf("%d %d %d\n", i[0], i[1], i[2]);
    }
}