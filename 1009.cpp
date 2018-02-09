//1009.cpp
#include <cstdio>

int x[10][10] = {{0},
			 	 {1, 1},
				 {6, 2, 4, 8, 6}, 
				 {1, 3, 9, 7, 1},
				 {6, 4, 6},
				 {5, 5},
				 {6, 6},
				 {1, 7, 9 ,3, 1},
				 {6, 8, 4, 2, 6},
				 {1, 9, 1}};
int size[10] = {0, 1, 4, 4, 2, 1, 1, 4, 4, 2};
int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		int a, b; scanf("%d %d", &a, &b);
		if(a % 10 == 0) printf("10\n");
		else printf("%d\n", x[a%10][b%size[a%10]]);
	}	
}
