#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;
int map[MAX][MAX];			// 인덱스 1~1000을 사용한다. 
int visit[MAX][MAX][2];
// [][][0]은 벽을 부수지 않고 이동한 경로
// [][][1]은 벽을 부수고 이동한 경로
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};	// 상하좌우 탐색에 사용 

void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &map[i][j]);
		}
	}
} 

// 맵 범위 내에 좌표 존재 여부 리턴. 
bool isIn(int x, int y){
	return x>=1&&x<=N&&y>=1&&y<=M;
}

int solve(){
	queue< pair<pair<int, int>, bool> > q;
	// x좌표, y좌표, 벽 부순 여부
	
	q.push(make_pair(make_pair(1, 1), 0));
	visit[1][1][0] = 1; 
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool z = q.front().second;
		q.pop();
		// 이번에 큐에서 꺼낸 위치가 도착 위치라면 리턴!
		if( x==N && y==M ) return visit[x][y][z]; 
		
		for(int i=0; i<4; i++){
			int nx = x+d[i][0];
			int ny = y+d[i][1];
			
			if( isIn(nx, ny)&&map[nx][ny]==0&&visit[nx][ny][z]==0){
				// 새 위치가 길이고
				// 이 위치에 방문한 적 없다면 
				// 전에 벽 부순 여부에 상관없이
				// 그 상태를 유지하며 방문표시! 
				visit[nx][ny][z] = visit[x][y][z]+1;
				q.push(make_pair(make_pair(nx, ny),z));
			}
			if( isIn(nx, ny)&&z==0&&map[nx][ny]==1&&visit[nx][ny][1]==0){
				// 벽을 부순적 없고,
				// 새 위치가 벽이며,
				// 이 벽을 아직 부수고 방문한 적 없을 때 
				visit[nx][ny][1] = visit[x][y][0]+1;
				q.push(make_pair(make_pair(nx, ny),1));
					// 앞으로는 벽을 부순 경로만 탐색할것임! 
			}
		}
	}
	return -1;
}

int main(){
	input();
	cout<<solve();
	return 0;
}
