#include <iostream>
#include <cstdio>
#include <algorithm>

long long int num;
int digit[10];

bool comp(int a, int b){
	return a>b;
}
int main(){
	scanf("%lld", &num);
	if( num > 1000000000 ) return 0;
	// �Է¹��� ���� �ڸ����� ���. 
	int t=1, digits=1;
	while( num >= t ){
		t*=10;
		digits++;	
	}
	// �� �ڸ����� digit�迭�� �ϳ��� ����. 
	for(int i=0; i<10; i++){
		int tmp = num%10;
		digit[i] = tmp;
		num/=10;
	}
	// digit�迭�� ������ ������������ ����. 
	std::sort(digit, digit+10, comp);
	// �ڸ�����ŭ digit�迭�� ������ ����Ѵ�. 
	for(int i=0; i<digits-1; i++){
		printf("%d", digit[i]);
	}
	return 0;
}
