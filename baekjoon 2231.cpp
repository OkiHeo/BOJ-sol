#include <cstdio>

// 분해합을 구하는 함수 decomp 
int decomp(int n){
	int t = 1;
	while( n >= t ){
		t*=10;
	}
	t/=10;
	int sum=0, temp = n;		// sum에 각 자릿수의 합을 저장. 
	while( t!=0 ){
		sum+=temp/t;
		temp%=t;
		t/=10;
	}
	return sum+n;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=1; i<1000000; i++){	// i를 1에서부터 키워가며 분해합과 N을 비교 
		int temp = decomp(i);		// i의 분해합을 temp에 저장 
		if( temp == N ){			// i의 분해합이 N과 같다면 i가 생성자 
			printf("%d\n", i);
			return 0; 				// 가장 작은 생성자 출력 후 프로그램 종료 
		}
	}
	printf("0\n");					// 생성자가 존재하지않으므로 0을 출력 
	return 0;
}
