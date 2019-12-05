#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[101][101];				// 인덱스 1~100 사용(총 100칸)
bool visit[101][101] = {false,};// 방문 체크 
int v[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int cnt;						// 지나야하는 칸 수 
queue< pair<int, int> > q;

void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &map[i][j]);
}

bool isIn(int x, int y){
	return x>0&&x<=N&&y>0&&y<=M;
}
void solve(int i, int j){
	visit[i][j]=true; 
	q.push(make_pair(i, j));
	cnt=1;
	while(!q.empty()){
		int size = q.size();
		for(int z=0; z<size; z++){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			if( x==N && y==M ){		// 도착점에 도착하면 solve함수 종료 
				return;
			} 
			for(int k=0; k<4; k++){
				int nx = x+v[k][0];
				int ny = y+v[k][1];
				// 미로 내에 존재하고, 길이라면 방문한다. 
				if( isIn(nx, ny)&&map[nx][ny]==1 ){
					if( visit[nx][ny]==true) continue;
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));								
				}
			}
		}
		cnt++;
	}
}
int main(){
	input();
	solve(1,1);
	printf("%d\n", cnt);
	return 0;
}
