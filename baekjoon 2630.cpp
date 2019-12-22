#include <iostream>
using namespace std;

int n;
bool paper[129][129];	// 인덱스 1~128을 사용한다. 
int white=0, blue=0;
int d[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}}; 

bool sameColor(int x, int y, int size){
	// (x,y)에서 시작하는 size*size가 모두 같은 색으로 칠해져있는지 체크 
	bool start = paper[x][y];
	bool flag = true;
	// (1,1)에서 시작해서 size가 8인경우, 1,..., 1+8-1까지. 
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			 if( start != paper[i][j] )
			 	flag = false;
		}
	}
	
	// 모든 색이 같다면 
	if( flag ){
		if(start==0)	// 그 색이 흰색이라면 흰 색종이+1 
			white++;
		else			// 그 색이 파란색이라면 파란 색종이+1 
			blue++;
	}
	// 모든 색이 같지 않다면 
	if( !flag ){
		// 4등분해서 같은 색인지 각각 또 비교한다. 
		for(int i=0; i<4; i++){
			sameColor(x+d[i][0]*size/2, y+d[i][1]*size/2, size/2);
		}
	}
	return flag;
}

void input(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>paper[i][j];
		}
	}
}

int main(){
	input();
	sameColor(1, 1, n);
	cout<<white<<'\n'<<blue<<'\n';
	return 0;
}
