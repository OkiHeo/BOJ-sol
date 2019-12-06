#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int tomato[1001][1001];					//�ε��� 1~1000 ����Ѵ�. 
queue <pair<int, int> > q;
int di[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};	// �����¿� �˻縦 ���� ��� 

void input(){
	cin>>M>>N;				// ���α���(��), ���� ����(��) ������ �Է¹޴´�. 
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>tomato[i][j];
			// �Է¹����鼭 ���� �丶���� ��ǥ�� ť�� �����Ѵ�.
			if( tomato[i][j]==1 ){				 
				q.push(make_pair(i,j));
			}
		}
	}
}

bool isIn(int x, int y){
	return x>0&&x<=N&&y>0&&y<=M;
}

int solve(){
	int x, y;
	for(int a=0; a<q.size(); a++){		// ó���� �Է¹��� ���� �丶�� ������ ���� �ݺ�. 
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			// �����¿� �丶�並 �˻��Ѵ�. 
			for(int i=0; i<4; i++){
				int nx = x+di[i][0];
				int ny = y+di[i][1];
				// ���� ���� ���� && ���� ���� �丶����
				// ���� ��ġ���� �Ϸ� ���Ŀ� ������ ǥ���ϰ� ť�� push �Ѵ�. 
				if( isIn(nx, ny)&&tomato[nx][ny]==0 ){
					tomato[nx][ny]=tomato[x][y]+1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	} 
	// ��� ������ ���� �� ���� ���� �丶�䰡 �ִٸ� -1 ����. �ƴϸ� day���� 
	int day = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			// ���� ���� �丶�䰡 �����ִٸ� -1�� ����Ѵ�. 
			if(tomato[i][j]==0) {
				return -1; 
			}
			day = max(day, tomato[i][j]-1);		// 0���� 1�Ϸ� ���Ƿ� �Ϸ縦 ���ش�. 
		}
	}
	return day;
} 

int main(){
	input();
	cout<<solve();
	return 0;
}
