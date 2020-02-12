#include <iostream>
using namespace std;

int T, M, N, K; 
int ground[50][50]; 
bool visit[50][50];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int i, int j){
	int x = i;
	int y = j;
	for(int tmp=0; tmp<4; tmp++){
		int newx = i+d[tmp][0];
		int newy = j+d[tmp][1];
		// ���ο� ��ġ�� �� ���ο� �����ϰ� 
		if( 0<=newx && newx<=M-1 && 0<=newy && newy<=N-1 ){
			// ���ο� ��ġ�� �����̸�, �湮���� ���� ������ �� 
			if( ground[newx][newy]==1 && visit[newx][newy]==false ){
				visit[newx][newy] = true;		// �湮ǥ��
				dfs(newx, newy); 
			}
		}
	}
}

int main(){
	/* �׽�Ʈ ���̽��� ���� T�Է� */
	cin>>T;
	for(int t=0; t<T; t++){
		/* ���߸� ���� ���߹��� ���� ���� M, ���α��� N, ���� ���� K�� �Է�*/
		cin>>M>>N>>K;
		// ���߹� 0, visit�迭 false�� �ʱ�ȭ.
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				ground[i][j] = 0;
				visit[i][j] = false;
			}
		} 
		/* ������ ��ġ x,y��ǥ K�� �Է� */
		for(int k=0; k<K; k++){
			int x, y;
			cin>>x>>y;
			ground[x][y] = 1;
		}
		
		/* �� ���̽��� ���� �ʿ��� �ּ��� ���������� ���� ���� ���*/
		int cnt=0;
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				if( ground[i][j]==1 && visit[i][j]==false ){
					cnt++;
					// �� ���߿� ����� ���ߵ��� �湮ó���Ѵ�.
					dfs(i, j); 
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
