#include <cstdio>

int memo[31];

int tile(int x){
	if(x==0) return 1;	// 아무 것도 놓지 않는 것은 한가지 
	if(x==1) return 0;
	if(x==2) return 3;
	if( memo[x]!=0 ) return memo[x];
	int result = tile(x-2)*3;
	for(int i=4; i<=x; i+=2){
		result+=2*tile(x-i);
	}
	return memo[x]=result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", tile(n));
	return 0;
}
