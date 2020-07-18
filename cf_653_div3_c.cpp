#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int tc;	cin >> tc;
	while(tc--) {
		int n;
		string str;
		cin >> n >> str;

		vector<char> v;
		for(char c : str) {
			if(v.empty()) {
				v.push_back(c);
			} else {
				if(v[v.size()-1] == '(' && c == ')') {
					v.pop_back();
				} else {
					v.push_back(c);
				}
			}
		}

		cout << v.size() / 2 << "\n";
	}
}