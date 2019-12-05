#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[101][101];				// �ε��� 1~100 ���(�� 100ĭ)
bool visit[101][101] = {false,};// �湮 üũ 
int v[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int cnt;						// �������ϴ� ĭ �� 
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
			
			if( x==N && y==M ){		// �������� �����ϸ� solve�Լ� ���� 
				return;
			} 
			for(int k=0; k<4; k++){
				int nx = x+v[k][0];
				int ny = y+v[k][1];
				// �̷� ���� �����ϰ�, ���̶�� �湮�Ѵ�. 
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
