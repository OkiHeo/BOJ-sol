#include <iostream>
#include <stdio.h>
 
bool primeArr[123456*2+1];
int main()
{
	int n;
	while(1){
		scanf("%d", &n);
		if( n==0 ) break;
		// n보다 크고 2n보다 작거나 같은 소수의 개수를 구하자.
		std::fill_n(primeArr, 123456*2+1, true);	// 생성한 배열 true로 초기화 
		primeArr[0]=false;
		primeArr[1]=false;
		for(int i=2; i*i<=2*n; i++){
			// i가 소수가 아니면 pass! 
			if( primeArr[i] == false ){
				continue;
			}
			// i는 소수이므로 건너뛰고 i의 배수들이 소수가 아님을 표시 
			for(int j=i+i; j<=2*n; j+=i){
				primeArr[j] = false;
			}
		}
		
		// n보다 크고, 2n보다 작거나 같은 소수의 개수 출력 
		int cnt=0;
		for(int k=n+1; k<=2*n; k++){
			if(primeArr[k]==true){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	// n에 0이 입력될 때까지 계속 테스트케이스를 입력받는다. 
	return 0;
} 
