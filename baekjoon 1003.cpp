#include <cstdio>

int T;	// 테스트 케이스의 개수 
int n;
long long int memo[41];
long long int fibo(int i){
	if( i==0 ){
		memo[i] = 0;
		return 0;	
	}
	if( i==1 ){
		memo[i] = 1;
		return 1;	
	} 
	
	if( memo[i]!=0 ) return memo[i];
	return memo[i]= fibo(i-1)+fibo(i-2);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		if( n==0 )
			printf("1 0\n");		// fibo(0)에 대해서만 예외 출력 
		else
			printf("%d %d\n", fibo(n-1), fibo(n));
	} 
	return 0;
}
