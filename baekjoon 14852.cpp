#include <cstdio>

long long int memo[1000001][2];

long long int tile(int x){
	memo[0][0] = 0;
	memo[1][0] = 2;
	memo[2][0] = 7;
	memo[2][1] = 1;
	for(int i=3; i<=x; i++){
		// 2*{tile(i-3) + tile(i-4) + ... + tile(0)}부분을 빠르게 계산하기 위해 저장. 
		memo[i][1] = (memo[i-1][1]+memo[i-3][0])%1000000007;
		memo[i][0] = (3*memo[i-2][0]+2*memo[i-1][0]+2*memo[i][1])%1000000007;
	}
	return memo[x][0];
} 

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld\n", tile(n));
	return 0; 
}
