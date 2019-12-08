#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];		// 인덱스 1~1000을 사용.
int visit[1001][1001][2];	// 각 위치에 도달하는 경로.
//  [][][0] : 벽을 부수지 않은 경로
//  [][][1] : 벽을 부순 경로 
int di[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			int x;
			scanf("%1d", &map[i][j]);
		}
	}
}

// 맵 범위 내에 좌표가 존재하는지 체크 
bool isIn(int x, int y){
	return x>=1&&x<=N&&y>=1&&y<=M;
}

int findPath(){
	queue< pair<pair<int, int>, bool > > q;
	q.push(make_pair(make_pair(1, 1), 0));
	visit[1][1][0] = 1;		// 벽과 구분하기 위해서 첫 시작점에 2를 저장한다. 
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool z = q.front().second;
		q.pop();
		if( x==N && y==M ) return visit[x][y][z];
		for(int i=0; i<4; i++){
			int nx = x+di[i][0];
			int ny = y+di[i][1];
			// 상하좌우의 새 위치가 범위 내에 존재할 때 접근. 
			if( isIn(nx, ny) ){
				// 새 위치가 길이고, 벽을 부순 적 없을 때 
				if( map[nx][ny]==0 && visit[nx][ny][z]==0 ){
					visit[nx][ny][z] = visit[x][y][z]+1;
					q.push(make_pair(make_pair(nx, ny), z));
						// 이전에 가지고 있던 벽을 부순 상태를 가지고 탐색 
				}
				// 새 위치가 벽이고, 벽을 부순 적 없을 때 
				if( map[nx][ny]==1 && z==0 && visit[nx][ny][0]==0 ){
					visit[nx][ny][1] = visit[x][y][0]+1;
					q.push(make_pair(make_pair(nx, ny), 1));
						// 앞으로는 벽을 부순 경로를 탐색할것임 
				}
			}
		}	
	}
	return -1;
}

int main(){
	input();
	printf("%d\n", findPath());
	return 0;
}
