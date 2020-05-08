#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/60058
    2020 Kakao Blind Recruitment    
*/

bool isRight(string str) {
    // 올바른 괄호 문자열인지 확인
    int leftCnt = 0;
    for(char c : str) {
        if(c == '(') leftCnt++;
        if(c == ')') {
            leftCnt--;
            if(leftCnt < 0) return false;
        }
    }
    return true;
}

string rev(string str) {
    if(str == "") return "";
    string ret;
    str.pop_back();
    str = str.substr(1);
    for(char c : str) {
        if(c == '(') ret.push_back(')');
        if(c == ')') ret.push_back('(');
    }
    return ret;
}

string f(string w) {
    if(w == "") return "";
    string u = "";
    string v = "";
    
    //split
    int leftCnt = 0, rightCnt = 0;
    for(int i=0;i<w.size();i++) {
        if(w[i] == '(') leftCnt++;
        if(w[i] == ')') rightCnt++;
        if(leftCnt == rightCnt) {
            u = w.substr(0, i+1);
            // cout << "u : " << u << endl;
            if(i == w.size()) break;
            v = w.substr(i+1);
            // cout << "v : " << v << endl;
            break;
        }
    }
        
    if(isRight(u)) {
        return u + f(v);
    } else {
        // u 의 앞뒤를 자르고 뒤집기
        return "(" + f(v) + ")" + rev(u);
    }
}

string solution(string p) {
    return f(p);
}