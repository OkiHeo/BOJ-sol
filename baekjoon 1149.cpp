#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int N;
int house[1001][3];
int tmp[3];		// 현재까지 선택의 최솟값들 저장. 
int choice[3];

int answer(){
	tmp[0] = house[1][0];	// 첫번째 집에서 빨강 선택 
	tmp[1] = house[1][1];	// 첫번째 집에서 초록 선택 
	tmp[2] = house[1][2];	// 첫번째 집에서 파랑 선택 
	
	// 두번째 집부터 마지막 집까지 순회 
	for(int num=2; num<=N; num++){
		// 새 집에서 빨강 선택 <- 이전 집에서 초록, 파랑 선택한 결과 중 작은것 
		choice[0] = house[num][0]+min(tmp[1], tmp[2]); 
		// 새 집에서 초록 선택 <- 이전 집에서 빨강, 파랑 선택한 결과 중 작은것
		choice[1] = house[num][1]+min(tmp[0], tmp[2]);
		// 새 집에서 파랑 선택 <- 이전 집에서 빨강, 초록 선택한 결과 중 작은것
		choice[2] = house[num][2]+min(tmp[0], tmp[1]);
		
		// 각 결과들을 재사용할 수 있도록 저장. 
		tmp[0] = choice[0];
		tmp[1] = choice[1];
		tmp[2] = choice[2];
	}
	
	// 모든 집을 순회한 후, 제일 마지막 집에서 빨강, 초록, 파랑 선택한 누적 결과 중 최솟값 리턴 
	return min(min(tmp[0], tmp[1]), tmp[2]);
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		// 각 집을 빨강, 초록, 파랑으로 칠하는 비용 
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}
	printf("%d\n", answer());
	return 0;
}
