#include <iostream>
#include <cstdio>
using namespace std;

int n;		// max 64
int video[65][65];

void compress(int x, int y, int size){
	// 해당범위의 첫 값을 저장 
	int first = video[x][y];
	bool same = true;
	
	// size가 1이라면 무조건 출력한다.(더이상 분할할수없으므로) 
	if( size==1 ){
		cout<<first;
		return;
	}
	
	// 범위 내 값을 첫 값과 비교하며 같지 않다면 same을 false로 바꾼다 
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			if( first != video[i][j] ){
				same = false;
			}
		}
	}
	
	// 범위 내 모든 값이 같다면 첫 값을 출력하고 함수 종료 
	if( same ){
		cout<<first;
		return;
	}
	// 범위 내 값이 모두 같지 않다면 4분할하여 비교한다. 
	else{
		cout<<"(";
		compress(x, y, size/2);					// 2사분면 
		compress(x, y+size/2, size/2);			// 1사분면 
		compress(x+size/2, y, size/2);			// 3사분면 
		compress(x+size/2, y+size/2, size/2);	// 4사분면 
		cout<<")";
	}
	return;
} 

int main(){
	// 입력 
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){ 
			// 한 줄로 입력받는 데이터를 하나하나 배열에 저장한다 
			scanf("%1d", &video[i][j]);
		}
	}
	// 압축 
	compress(1, 1, n);
	return 0;
}
