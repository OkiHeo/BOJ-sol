#include <iostream>
#include <cstdio>
using namespace std;

int N;
int num[12];
int op[4];
// 결과의 최댓값과 최솟값은 절댓값 10억을 넘지 않는다. 
int ret_min = 1000000001, ret_max=-1000000001;

void answer(int result, int count){
	if( count==N-1 ){
		if(ret_min>result)
			ret_min = result;
		if(ret_max<result)
			ret_max = result;
		return;
	}
	
	// N개의 수로 이루어진 수열에 대해 연산 진행.
	// N-1개의 연산자 
	for(int i=0; i<4; i++){
		if( op[i]>0 ){
			op[i]--;
			
			if(i==0){
			answer(result+num[count+1], count+1);
			}
			if(i==1){
			answer(result-num[count+1], count+1);
			}
			if(i==2){
			answer(result*num[count+1], count+1);
			}
			if(i==3){
			answer(result/num[count+1], count+1);
			}
			
			op[i]++;
		}
	}
}

int main(){
	// 숫자의 개수, 수열 입력 
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}
	// 연산자의 개수 입력. + - * / 순서 
	for(int i=0; i<4; i++){
		scanf("%d", &op[i]);
	}
	
	answer(num[0], 0);
	// 최댓값, 최솟값 출력 
	printf("%d\n%d", ret_max, ret_min);
	return 0;
} 
