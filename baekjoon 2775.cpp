#include <iostream>
#include <stdio.h>

int howmany(int k, int n){
	int sum=0;
	if( k == 0 ){
		return n;
	}
	for( int i=1; i<=n; i++){
		sum+= howmany(k-1, i);
	}
	return sum;
}
int main()
{
	int T;
	scanf("%d", &T);
	int k, n;
	while(T--){
		scanf("%d", &k);
		scanf("%d", &n);
		
		printf("%d\n", howmany(k, n));
	}	
	return 0;
}
