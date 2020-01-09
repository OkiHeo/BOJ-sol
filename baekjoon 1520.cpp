#include <iostream>
using namespace std;

int m, n;
// map�� dp�迭 (1,1) ~ (m,n) ��� 
int map[501][501];
int dp[501][501];
int d[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isIn(int x, int y){
	return x>=1&&x<=m&&y>=1&&y<=n;
}

int downhill(int x, int y){
	if( dp[x][y]!=-1 ) return dp[x][y];	// �̹� ����� �� �ִٸ� �� �� ���� 
	if( !isIn(x, y)) return 0;			// ������ ����ٸ� �� ������ ���� ����� ���� 0�̴� 
	if( x==1 && y==1 ) return 1;		//(1,1)���� ����ؼ� (1,1)�� �����ϴ� ����� �� : 1 
	
	dp[x][y] = 0;		// dp�� ���� ����� ���� 0���� �ʱ�ȭ�ϰ� ���ؾ��Ѵ�. 
	 
	for(int di=0; di<4; di++){
		// (x,y)�� �����¿� Ž�� 
		int nextX = x+d[di][0];
		int nextY = y+d[di][1];
		// (x,y)���� (nextX,nextY)�� ���̰� ���ٸ�
		// (x,y)���� ���� ����� �� += �� (nextX,nextY)���� ���� ����� �� 
		if( map[nextX][nextY] > map[x][y] ){
			dp[x][y] += downhill(nextX, nextY);
		}
	}
	// ���� (x,y)���� ���� ����� ���� �����Ѵ�. 
	return dp[x][y];	
}
int main(){
	cin>>m>>n;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cin>>map[i][j];
			dp[i][j]=-1;	// dp�迭 -1�� �ʱ�ȭ. 
		}
	}
	cout<<downhill(m,n)<<'\n';
	return 0;
}
