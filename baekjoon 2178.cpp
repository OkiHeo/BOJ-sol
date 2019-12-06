#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int N, M;
int map[101][101];				// �ε��� 1~100 ���(�� 100ĭ)
int visit[101][101];			// �湮 üũ. ������� ���µ� �� ĭ �ɷȴ°� 
int v[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
queue< pair<int, int> > q;
void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &map[i][j]);
}
// ���� ���� �����ϴ��� üũ 
bool isIn(int x, int y){
	return x>0&&x<=N&&y>0&&y<=M;
}
void solve(int i, int j){
	map[i][j] = 9;
	visit[i][j]=1;					// �� �������� �湮�ߴٴ� ��! 
	q.push(make_pair(i, j));
	
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++){
			// �����¿츦 üũ 
			int nx = x+v[k][0];
			int ny = y+v[k][1];
			// �̷� ���� �����ϰ�, ���̶�� �湮�Ѵ�. 
			if( isIn(nx, ny)&&map[nx][ny]==1 ){
				visit[nx][ny] = visit[x][y]+1;	// �� ������ �湮�ߴٴ� ��! 
				map[nx][ny] = 9;		// �� ������ �ٽ� �湮���� �ʵ��� 0�� 1�� �ƴ� ���� �ٲ��� 
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
