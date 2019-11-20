#include <iostream>
#include <cstdio>

void hanoi(int from, int by, int to, int n){
	if( n <= 1 ){
		printf("%d %d\n", from, to);
		return;
	}
	else{
		hanoi(from, to, by, n-1);
		hanoi(from, by, to, 1);
		hanoi(by, from, to, n-1);
	}
}
int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", (1<<N)-1);
	hanoi(1, 2, 3, N);
	return 0;
}
