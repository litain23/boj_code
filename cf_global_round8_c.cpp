#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int k;
	cin >> k;

	cout << k * 3 + 4 << "\n";
	printf("0 0\n");
	printf("0 1\n");
	for(int i=1;i<=k;i++) {
		printf("%d %d\n", i, i-1);
		printf("%d %d\n", i, i);
		printf("%d %d\n", i, i+1);
	}
	printf("%d %d\n", k+1, k);
	printf("%d %d\n", k+1, k+1);
}