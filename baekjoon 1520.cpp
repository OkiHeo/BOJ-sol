#include <iostream>
using namespace std;

int m, n;
// map과 dp배열 (1,1) ~ (m,n) 사용 
int map[501][501];
int dp[501][501];
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isIn(int x, int y){
	return x>=1&&x<=m&&y>=1&&y<=n;
}

int downhill(int x, int y){
	if( dp[x][y]!=-1 ) return dp[x][y];	// 이미 계산한 적 있다면 그 값 리턴 
	if( !isIn(x, y)) return 0;			// 범위를 벗어났다면 그 곳까지 가는 경우의 수는 0이다 
	if( x==1 && y==1 ) return 1;		//(1,1)에서 출발해서 (1,1)에 도착하는 경우의 수 : 1 
	
	dp[x][y] = 0;		// dp를 새로 계산할 때는 0으로 초기화하고 더해야한다. 
	 
	for(int di=0; di<4; di++){
		// (x,y)의 상하좌우 탐색 
		int nextX = x+d[di][0];
		int nextY = y+d[di][1];
		// (x,y)보다 (nextX,nextY)의 높이가 높다면
		// (x,y)까지 가는 경우의 수 += 각 (nextX,nextY)까지 가는 경우의 수 
		if( map[nextX][nextY] > map[x][y] ){
			dp[x][y] += downhill(nextX, nextY);
		}
	}
	// 계산된 (x,y)까지 가는 경우의 수를 리턴한다. 
	return dp[x][y];	
}
int main(){
	cin>>m>>n;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cin>>map[i][j];
			dp[i][j]=-1;	// dp배열 -1로 초기화. 
		}
	}
	cout<<downhill(m,n)<<'\n';
	return 0;
}
