#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, M;
int map[101][101];				// 인덱스 1~100 사용(총 100칸)
int visit[101][101];			// 방문 체크. 여기까지 오는데 몇 칸 걸렸는가 
int v[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
queue< pair<int, int> > q;
void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &map[i][j]);
}
// 범위 내에 존재하는지 체크 
bool isIn(int x, int y){
	return x>0&&x<=N&&y>0&&y<=M;
}
void solve(int i, int j){
	map[i][j] = 9;
	visit[i][j]=1;					// 이 지점에는 방문했다는 뜻! 
	q.push(make_pair(i, j));
	
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++){
			// 상하좌우를 체크 
			int nx = x+v[k][0];
			int ny = y+v[k][1];
			// 미로 내에 존재하고, 길이라면 방문한다. 
			if( isIn(nx, ny)&&map[nx][ny]==1 ){
				visit[nx][ny] = visit[x][y]+1;	// 이 지점에 방문했다는 뜻! 
				map[nx][ny] = 9;		// 이 지점에 다시 방문하지 않도록 0과 1이 아닌 수로 바꿔줌 
				q.push(make_pair(nx, ny));								
			}
		}
	}
}
int main(){
	input();
	solve(1,1);
	printf("%d\n", visit[N][M]);
	return 0;
}
