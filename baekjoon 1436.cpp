#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);		// 몇 번째 영화의 제목이 궁금한지 
	
	int cnt=1, number=666;	// 666은 가장 작은 종말의수  
	int a, b, c;	// 연속된 세 자리의 자릿수를 저장할 변수 
	while(1){
		if( cnt == N ) break;
		number++;
		int numcopy = number;
		int serial = 0;
		while( numcopy ){
			int temp = numcopy%10;	// 일의 자리수부터 차례로 비교 
			if( temp == 6 ){
				serial++;
			}
			else if( serial<3 ){	// 그 다음 수가 6이 아니면 serial 초기화 
				serial = 0;			// 6이 연속으로 안나왔으므로! 
			}
			numcopy/=10;			// 그 다음 자리수가 일의 자리수로 오도록 
		}							// 현재 number의 모든 자리수 비교 완료 
		if( serial >= 3 ){			// 6이 세 번 이상 연속으로 등장 
			cnt++;
		} 
	}
	printf("%d\n", number);
	return 0;
}
