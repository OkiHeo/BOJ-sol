#include <iostream>
using namespace std;

int n, m, k;	// 통로의 세로길이, 가로길이, 음식물 쓰레기 개수
bool trash[101][101];	// [1][1] ~ [n][m] 사용.
bool visit[101][101];
int tmpbunch=0;
int bunch=0;		// 가장 큰 음식물 쓰레기의 크기 저장. 
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y){
	visit[x][y] = true;
	tmpbunch++;		// 현재 [x][y]개수를 tmpbunch에 추가. 
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 1<=newx&&newx<=n&&1<=newy&&newy<=m ){
			if( trash[newx][newy]==true && visit[newx][newy]==false ){
				visit[newx][newy] = true;
				dfs(newx, newy); 
			}
		}
	}
} 

int main(){
	/* 통로의 세로길이, 가로길이, 음식물 쓰레기 개수 입력*/
	cin>>n>>m>>k;
	/* k개의 음식물이 떨어진 좌표 입력 */
	for(int K=0; K<k; K++){
		int x, y;
		cin>>x>>y;
		trash[x][y] = 1;
	}
	
	/* 음식물 중 가장 큰 음식물의 '크기'를 출력 */
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			// 음식물 쓰레기를 찾는다. 
			if( trash[i][j]==true ){
				// 방문한 적 없는 쓰레기라면 그 쓰레기에 연결된 쓰레기 탐색. 
				if( visit[i][j]==true ) continue;
				else{
					dfs(i, j);	
				}
			}
			bunch = max(bunch, tmpbunch);
			tmpbunch=0;
		}
	}
	cout<<bunch<<'\n';
	return 0;
} 
