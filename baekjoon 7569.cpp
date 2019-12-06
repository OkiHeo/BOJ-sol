#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M, H;
int tomato[101][101][101];					//�ε��� 1~1000 ����Ѵ�. 
queue <pair<pair<int, int>, int> > q;
int di[6][3] = {{0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}, {0,0,-1}, {0,0,1}};	// �����¿� �˻縦 ���� ��� 

void input(){
	cin>>M>>N>>H;				// ���α���(��), ���� ����(��) ������ �Է¹޴´�. 
	for(int k=1; k<=H; k++)
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				cin>>tomato[i][j][k];
				// �Է¹����鼭 ���� �丶���� ��ǥ�� ť�� �����Ѵ�.
				if( tomato[i][j][k]==1 ){				 
					q.push(make_pair(make_pair(i,j),k));
				}	
			}
		}
}

bool isIn(int x, int y, int z){
	return x>0&&x<=N&&y>0&&y<=M&&z>0&&z<=H;
}

int solve(){
	int x, y, z;
	for(int a=0; a<q.size(); a++){		// ó���� �Է¹��� ���� �丶�� ������ ���� �ݺ�. 
		while(!q.empty()){
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			// �����¿� �丶�並 �˻��Ѵ�. 
			for(int i=0; i<6; i++){
				int nx = x+di[i][0];
				int ny = y+di[i][1];
				int nz = z+di[i][2];
				// ���� ���� ���� && ���� ���� �丶����
				// ���� ��ġ���� �Ϸ� ���Ŀ� ������ ǥ���ϰ� ť�� push �Ѵ�. 
				if( isIn(nx, ny, nz)&&tomato[nx][ny][nz]==0 ){
					tomato[nx][ny][nz] = tomato[x][y][z]+1;
					q.push(make_pair(make_pair(nx, ny), nz));
				}
			}
		}
	} 
	// ��� ������ ���� �� ���� ���� �丶�䰡 �ִٸ� -1 ����. �ƴϸ� day���� 
	int day = 0;
	for(int k=1; k<=H; k++)
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				// ���� ���� �丶�䰡 �����ִٸ� -1�� ����Ѵ�. 
				if(tomato[i][j][k]==0) {
					return -1; 
				}
				day = max(day, tomato[i][j][k]-1);
					// 0���� 1�Ϸ� ���Ƿ� �Ϸ縦 ���ش�. 	
			}
		}
	return day;
} 

int main(){
	input();
	cout<<solve();
	return 0;
}
