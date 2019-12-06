/* 11053번
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하자 */

#include <cstdio>
#include <iostream>
using namespace std;

int N;                                    // 최대 1000
int serial[1001];                       // 수열의 i번째 수 저장
int upSerial[1001];                   // i번째 수까지 존재하는 증가 수열의 수

void input(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &serial[i]);
	}
}

int solve(){
	int maxxx = 0;
	fill_n(upSerial, 1001, 1);      // upSerial배열을 모두 1로 초기화한다.
	for(int i=1; i<=N; i++){
		for(int j=1; j<i; j++){
			if( serial[j] < serial[i] )
			upSerial[i] = max(upSerial[i], upSerial[j]+1);
		}
		maxxx = max(maxxx, upSerial[i]);     // 가장 큰 upSerial값을 maxxx에 저장.
	}
	return maxxx;
}

int main(){
	input();
	printf("%d\n", solve());        // 수열 A에 존재하는 가장 긴 증가하는 부분수열 길이 출력
	return 0;
}

