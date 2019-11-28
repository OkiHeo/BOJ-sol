#include <iostream>
#include <cstdio>
using namespace std;

int N;
int num[12];
int op[4];
// ����� �ִ񰪰� �ּڰ��� ���� 10���� ���� �ʴ´�. 
int ret_min = 1000000001, ret_max=-1000000001;

void answer(int result, int count){
	if( count==N-1 ){
		if(ret_min>result)
			ret_min = result;
		if(ret_max<result)
			ret_max = result;
		return;
	}
	
	// N���� ���� �̷���� ������ ���� ���� ����.
	// N-1���� ������ 
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
	// ������ ����, ���� �Է� 
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}
	// �������� ���� �Է�. + - * / ���� 
	for(int i=0; i<4; i++){
		scanf("%d", &op[i]);
	}
	
	answer(num[0], 0);
	// �ִ�, �ּڰ� ��� 
	printf("%d\n%d", ret_max, ret_min);
	return 0;
} 
