#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];		// �ε��� 1~1000�� ���.
int visit[1001][1001][2];	// �� ��ġ�� �����ϴ� ���.
//  [][][0] : ���� �μ��� ���� ���
//  [][][1] : ���� �μ� ��� 
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

// �� ���� ���� ��ǥ�� �����ϴ��� üũ 
bool isIn(int x, int y){
	return x>=1&&x<=N&&y>=1&&y<=M;
}

int findPath(){
	queue< pair<pair<int, int>, bool > > q;
	q.push(make_pair(make_pair(1, 1), 0));
	visit[1][1][0] = 1;		// ���� �����ϱ� ���ؼ� ù �������� 2�� �����Ѵ�. 
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool z = q.front().second;
		q.pop();
		if( x==N && y==M ) return visit[x][y][z];
		for(int i=0; i<4; i++){
			int nx = x+di[i][0];
			int ny = y+di[i][1];
			// �����¿��� �� ��ġ�� ���� ���� ������ �� ����. 
			if( isIn(nx, ny) ){
				// �� ��ġ�� ���̰�, ���� �μ� �� ���� �� 
				if( map[nx][ny]==0 && visit[nx][ny][z]==0 ){
					visit[nx][ny][z] = visit[x][y][z]+1;
					q.push(make_pair(make_pair(nx, ny), z));
						// ������ ������ �ִ� ���� �μ� ���¸� ������ Ž�� 
				}
				// �� ��ġ�� ���̰�, ���� �μ� �� ���� �� 
				if( map[nx][ny]==1 && z==0 && visit[nx][ny][0]==0 ){
					visit[nx][ny][1] = visit[x][y][0]+1;
					q.push(make_pair(make_pair(nx, ny), 1));
						// �����δ� ���� �μ� ��θ� Ž���Ұ��� 
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
