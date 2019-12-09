#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;
int map[MAX][MAX];			// �ε��� 1~1000�� ����Ѵ�. 
int visit[MAX][MAX][2];
// [][][0]�� ���� �μ��� �ʰ� �̵��� ���
// [][][1]�� ���� �μ��� �̵��� ���
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};	// �����¿� Ž���� ��� 

void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &map[i][j]);
		}
	}
} 

// �� ���� ���� ��ǥ ���� ���� ����. 
bool isIn(int x, int y){
	return x>=1&&x<=N&&y>=1&&y<=M;
}

int solve(){
	queue< pair<pair<int, int>, bool> > q;
	// x��ǥ, y��ǥ, �� �μ� ����
	
	q.push(make_pair(make_pair(1, 1), 0));
	visit[1][1][0] = 1; 
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool z = q.front().second;
		q.pop();
		// �̹��� ť���� ���� ��ġ�� ���� ��ġ��� ����!
		if( x==N && y==M ) return visit[x][y][z]; 
		
		for(int i=0; i<4; i++){
			int nx = x+d[i][0];
			int ny = y+d[i][1];
			
			if( isIn(nx, ny)&&map[nx][ny]==0&&visit[nx][ny][z]==0){
				// �� ��ġ�� ���̰�
				// �� ��ġ�� �湮�� �� ���ٸ� 
				// ���� �� �μ� ���ο� �������
				// �� ���¸� �����ϸ� �湮ǥ��! 
				visit[nx][ny][z] = visit[x][y][z]+1;
				q.push(make_pair(make_pair(nx, ny),z));
			}
			if( isIn(nx, ny)&&z==0&&map[nx][ny]==1&&visit[nx][ny][1]==0){
				// ���� �μ��� ����,
				// �� ��ġ�� ���̸�,
				// �� ���� ���� �μ��� �湮�� �� ���� �� 
				visit[nx][ny][1] = visit[x][y][0]+1;
				q.push(make_pair(make_pair(nx, ny),1));
					// �����δ� ���� �μ� ��θ� Ž���Ұ���! 
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
