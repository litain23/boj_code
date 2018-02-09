//9243.cpp
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	int n; scanf("%d", &n);
	string str1, str2;
	cin >> str1 >> str2;

	bool ans = true;
	for(int i=0;i<str1.size();i++){
		if(n%2){
			if(str1[i] == str2[i]) {ans = false; break;}
		}
		else{
			if(str1[i] != str2[i]) {ans = false; break;}
		}
	}

	if(ans) printf("Deletion succeeded");
	else printf("Deletion failed");
}

