#include <cstdio>

int n;
long long int memo[91];
long long int fibo(int i){
	if( i==0 ) return 0;
	if( i==1 ) return 1;
	
	if( memo[i]!=0 ) return memo[i];
	return memo[i] = fibo(i-1)+fibo(i-2);
} 

int main(){
	scanf("%d", &n);
	printf("%lld", fibo(n));
		// 최대 90번째 피보나치수 출력할수있으므로 
		// 아주 큰 수 출력에 대비해야한다! 
	return 0;
}
