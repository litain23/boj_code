//z_alogorithm
#include <cstdio>
#include <string>
using namespace std;

int R, L, z[100001]; 
int main(){
	string a;
	cin >> a;
	int n = a.size();
	for(int i=1;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && a[R-L] == a[R]) R++;
			z[i] = R - L; R--;
		}
		else{
			int k = i - L;
			if(z[k] < R - i + 1) z[i] = z[k];
			else{
				L = i;
				while(R < n && a[R-L] == a[R]) R++;
				z[i] = R - L; R--;
			}
		}
	}
}
