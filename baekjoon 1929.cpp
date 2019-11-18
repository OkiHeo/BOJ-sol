#include <iostream>
#include <stdio.h>

bool primeArr[1000001];
// 1~1000000인덱스값 1이면 소수이다.
// 1,000,000정도의 수는 크기때문에
// 에라토스테네스의 체를 이용해보도록 하자. 

void prime(int m, int n){
	//primeArr의 값을 모두 1으로 초기화한다.
	std::fill_n(primeArr, 1000001, 1);
	// 1이 소수가 아님을 표시한다.
	primeArr[1] = 0;
	// 2부터 n의 제곱근까지 반복하며 에라토스테네스의 체 알고리즘 수행
	for(int q=2; q*q<=n; q++){
		if(primeArr[q] == 0){
			continue;
		}
		for(int k=q+q; k<=n; k+=q){
			primeArr[k]=0;
		}
	}	
}

int main()
{
	int M, N;
	std::cin>>M>>N;
	
	prime(M, N);
	
	//M과 N사이의 소수(primeArr[] == 1 ) 출력 
	for(int i=M; i<=N; i++){
		if(primeArr[i]==1){
			printf("%d\n", i);
		}
	} 
	return 0;
}
