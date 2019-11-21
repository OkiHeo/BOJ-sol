#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b){
	return a<b?a:b;
}

int calCnt(const char board[52][52], int i, int j) {
	int cnt = 0;					// 새로 칠해야 할 칸의 개수 
	for (int p = 0; p<8; p++) {
		for (int q = 0; q<8; q++) {
			if( p%2==0 ){
				if( q%2==0 ){
					if( 'B' == board[i+p][j+q])
						cnt++;
				}
				else{
					if( 'W' == board[i+p][j+q])
						cnt++;
				}
			}
			else{
				if( q%2==0 ){
					if( 'W' == board[i+p][j+q])
						cnt++;
				}
				else{
					if( 'B' == board[i+p][j+q])
					cnt++;
				}
			}
		}
	}
	return cnt;
}

char board[52][52];

int main() {
	int N, M;
	cin>>N>>M;

	// 주어진 보드의 상태 입력!!! 
	for (int i = 1; i<=N; i++) {
		for(int j=1; j<=M; j++)
			cin>>board[i][j];
	}

	int Min = 3000;	// 새로 칠해야하는 칸의 최소 개수
	for (int i = 1; i<=N-7; i++) {
		for (int j = 1; j<=M-7; j++) {
			int cnt = calCnt(board, i, j);
			cnt = min(cnt, 64-cnt);
			Min = min(Min, cnt);
		}
	}
	printf("%d\n", Min);
	return 0;
}
