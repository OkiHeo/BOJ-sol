#include <cstdio>

int memo[1001];
int dp(int x){
	if( x==1 ) return 1;
	if( x==2 ) return 3;
	if( memo[x]!=0 ) return memo[x];
	return memo[x] = (dp(x-1) + 2*dp(x-2))%10007;	
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", dp(n));
	return 0;
}
