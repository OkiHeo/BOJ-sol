#include <iostream>
using namespace std;

int n;
char pic[101][101];
bool visit[101][101];
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int rgb=0, nonrgb=0;

void RGBpeople(int x, int y, char now){
	visit[x][y] = true;
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 0<=newx&&newx<n && 0<=newy&&newy<n ){
			if( visit[newx][newy]==true ) continue;		// 이미 방문했던 지점은 패스 
			// 현재 탐색중인 색과 상하좌우 위치의 색이 같을때 
			if( now==pic[newx][newy] )
				RGBpeople(newx, newy, now);
		}
	}
}

void nonRGBpeople(int x, int y, char now){
	visit[x][y] = true;
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 0<=newx&&newx<n && 0<=newy&&newy<n ){
			if( visit[newx][newy]==true) continue;		// 방문했던 지점은 패스 
			// 현재 탐색중인 색이 'R' 또는 'G'일 때 
			if( now=='R'||now=='G'){
				if(pic[newx][newy]=='R'){
					nonRGBpeople(newx, newy, 'R');
				}
				else if(pic[newx][newy]=='G'){
					nonRGBpeople(newx, newy, 'G');
				}
			}
			// 현재 탐색중인 색이 'B'일 때 
			else{
				// 상하좌우가 현재 탐색중인 색과 같을때 
				if( now==pic[newx][newy] )
					nonRGBpeople(newx, newy, now);
			}
		}
	}
}

int main(){
	/* 그림이 입력으로 주어짐 */
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>pic[i];
	}

	/* 적록색약이 아닌 사람이 봤을 때 구역의 수 구하기 */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( visit[i][j]==false ){
				rgb++;
				RGBpeople(i, j, pic[i][j]);
			}
		}
	}
	
	/* visit 배열 초기화 */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visit[i][j] = false;
		}
	}
	
	/* 적록색약인 사람이 봤을 때 구역의 수 구하기 */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( visit[i][j]==false ){
				nonrgb++;
				nonRGBpeople(i, j, pic[i][j]);
			}
		}
	}
	
	cout<<rgb<<' '<<nonrgb<<'\n';
	return 0;
}
