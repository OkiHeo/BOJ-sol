#include <iostream>
#include <stdio.h>
using namespace std;
int T;	// 테스트 케이스 개수 
int H, W, N;	// 층 수, 방 수, 손님no 
int roomNo;		// N번째 손님 배정받을 방 

int main()
{
	// 테스트케이스 개수 입력 
	scanf("%d", &T);
	while(T--){
		// 층 수, 방 수, 손님 번호 입력 
		scanf("%d %d %d", &H, &W, &N);
		roomNo = 0;
		int height, width;
		/* 30 50 30의 경우 3001호가 아닌
		102호에 묵는 문제를 해결하기 위해*/
		if( N%H == 0 ){
			height = H;
			width = N/H;
		}
		else{
			height = N%H;
			width = N/H+1;
		}
		roomNo += height*100+width;
		
		// N번째 손님에게 배정될 방 번호 출력
		cout<<roomNo<<'\n';
	}
	return 0;
}
