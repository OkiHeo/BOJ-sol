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
		// �ִ� 90��° �Ǻ���ġ�� ����Ҽ������Ƿ� 
		// ���� ū �� ��¿� ����ؾ��Ѵ�! 
	return 0;
}
