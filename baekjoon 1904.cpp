#include <cstdio>
int N;
int memo[1000001];
int binary(int n){
	if( n==1 ) return 1;
	if( n==2 ) return 2;
	
	if( memo[n]!=0 ) return memo[n];
	// 15746���� ���� �������� ����ϴ� ���� ��ǥ�̹Ƿ�
	// ó������ 15746���� ���� �������� �������ش�. 
	return memo[n] = (binary(n-1)+binary(n-2))%15746;
}

int main(){
	scanf("%d", &N);
	printf("%d", binary(N));
	return 0;
}
