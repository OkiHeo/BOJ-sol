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
	// 입력받은 수의 자리수를 계산. 
	int t=1, digits=1;
	while( num >= t ){
		t*=10;
		digits++;	
	}
	// 각 자리수를 digit배열에 하나씩 저장. 
	for(int i=0; i<10; i++){
		int tmp = num%10;
		digit[i] = tmp;
		num/=10;
	}
	// digit배열의 내용을 내림차순으로 정렬. 
	std::sort(digit, digit+10, comp);
	// 자리수만큼 digit배열의 내용을 출력한다. 
	for(int i=0; i<digits-1; i++){
		printf("%d", digit[i]);
	}
	return 0;
}
