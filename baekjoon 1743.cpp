#include <iostream>
using namespace std;

int n, m, k;	// ����� ���α���, ���α���, ���Ĺ� ������ ����
bool trash[101][101];	// [1][1] ~ [n][m] ���.
bool visit[101][101];
int tmpbunch=0;
int bunch=0;		// ���� ū ���Ĺ� �������� ũ�� ����. 
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y){
	visit[x][y] = true;
	tmpbunch++;		// ���� [x][y]������ tmpbunch�� �߰�. 
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 1<=newx&&newx<=n&&1<=newy&&newy<=m ){
			if( trash[newx][newy]==true && visit[newx][newy]==false ){
				visit[newx][newy] = true;
				dfs(newx, newy); 
			}
		}
	}
} 

int main(){
	/* ����� ���α���, ���α���, ���Ĺ� ������ ���� �Է�*/
	cin>>n>>m>>k;
	/* k���� ���Ĺ��� ������ ��ǥ �Է� */
	for(int K=0; K<k; K++){
		int x, y;
		cin>>x>>y;
		trash[x][y] = 1;
	}
	
	/* ���Ĺ� �� ���� ū ���Ĺ��� 'ũ��'�� ��� */
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			// ���Ĺ� �����⸦ ã�´�. 
			if( trash[i][j]==true ){
				// �湮�� �� ���� �������� �� �����⿡ ����� ������ Ž��. 
				if( visit[i][j]==true ) continue;
				else{
					dfs(i, j);	
				}
			}
			bunch = max(bunch, tmpbunch);
			tmpbunch=0;
		}
	}
	cout<<bunch<<'\n';
	return 0;
} 
