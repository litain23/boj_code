#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/64062
    2019 Kakao Winter Internship
*/

int solution(vector<int> stones, int k) {
    int right = 200000000;
    int left = 1;
    int mid; 
    while(left + 1 < right) {
        mid = (left + right) / 2;
        int jump = 0;
        bool isOk = true;
        for(int i : stones) {
            i -= mid - 1;
            if(i <= 0) {
                jump++;
                if(jump >= k) {
                    isOk = false;
                    break;
                }
            } else {
             	jump = 0;   
            }
        }
        
        if(isOk) {
        	left = mid;
        } else {
        	right = mid;
        }
    }

    return left;
}