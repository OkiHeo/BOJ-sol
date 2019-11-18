#include <iostream>
#include <stdio.h>

bool prime(int n){
	if( n<2 )
		return false;
	for(int i=2; i*i<=n; i++){
		if( n%i == 0 )
			return false;
	}
	return true;
}

int main()
{
	int N, cnt=0;
	// 수의 개수 입력 
	scanf("%d", &N);
	// N개만큼의 수 입력 
	int *arr = new int[N];
	for(int i=0; i<N; i++){
		std::cin>>arr[i];
	}
	
	// 소수 판별하기
	for(int i=0; i<N; i++){
		if(prime(arr[i]))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
} 
