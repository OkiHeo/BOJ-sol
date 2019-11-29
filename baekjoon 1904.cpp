#include <cstdio>
int N;
int memo[1000001];
int binary(int n){
	if( n==1 ) return 1;
	if( n==2 ) return 2;
	
	if( memo[n]!=0 ) return memo[n];
	// 15746으로 나눈 나머지를 출력하는 것이 목표이므로
	// 처음부터 15746으로 나눈 나머지를 저장해준다. 
	return memo[n] = (binary(n-1)+binary(n-2))%15746;
}

int main(){
	scanf("%d", &N);
	printf("%d", binary(N));
	return 0;
}
