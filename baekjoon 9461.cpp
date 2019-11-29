#include <cstdio>

int T, N;
long long int memo[101];
long long int pn(int n){
	if( n==1 ) return 1;
	if( n==2 ) return 1;
	if( n==3 ) return 1;
	if( n==4 ) return 2;
	if( n==5 ) return 2;
	if( n==6 ) return 3;
	
	if( memo[n]!=0 ) return memo[n];
	return memo[n] = pn(n-1)+pn(n-5);
}
int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		printf("%lld\n", pn(N));
	}
} 
