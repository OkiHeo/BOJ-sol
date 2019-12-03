#include <iostream>

int memo[31][2];
// memo[n][0]에는 3xn타일을 칠하는 경우의 수 저장.
// memo[n][1]에는 3x(0) ~ 3x(n-2)타일을 칠하는 경우의 수의 합 저장.

int tile(int x){
	memo[0][0] = 1;
	memo[1][0] = 0;
	memo[2][0] = 3;
	memo[2][1] = 1;
	if( x%2!= 0) return 0;
	for(int i=4; i<=x; i+=2){
		memo[i][1] = memo[i-2][1] + memo[i-2][0];
		memo[i][0] = 3*memo[i-2][0] + 2*memo[i-2][1];	
	}
	return memo[x][0];
}

int main(){
	int n;
	std::cin>>n;
	std::cout<<tile(n)<<'\n';
	return 0;
}
