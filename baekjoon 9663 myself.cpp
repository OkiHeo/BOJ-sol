#include <iostream>
#include <cstdio>
using namespace std;

int N;
int count;			// 퀸을 놓을 수 있는 방법의 수 
bool col[15];		// 인덱스 : 열의 번호. 이 열에 퀸이 존재하는가. 
bool *dup;
bool *ddown;

void findQueen(int n){
	if( n==N ){		// n은 행을 가리킴. 0~n-1까지 조사 완료했으면 
		count++;	// count 증가 
	}
	else{
		for(int i=0; i<N; i++){
			if( col[i] ) continue;
			if( dup[n+i] || ddown[N-1+n-i]) continue;
			col[i] = dup[n+i] = ddown[N-1+n-i] = true;
			findQueen(n+1);
			col[i] = dup[n+i] = ddown[N-1+n-i] = false;
		}
	} 
}

int main(){
	scanf("%d", &N);
	dup = new bool[2*N-1];
	ddown = new bool[2*N-1];
	
	findQueen(0);
	
	printf("%d", count);		// 퀸을 놓을 수 있는 방법의 수 출력 
	delete[] dup;
	delete[] ddown;
	return 0;
}
