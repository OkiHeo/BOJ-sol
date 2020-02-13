#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/*2667 ������ȣ���̱� dfs�� Ǯ���*/

int n;
int danji=0, house[25*25/2+1];
int area[26][26];
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int x, int y, int dnum){
	area[x][y] = dnum;
	house[dnum-2]++;		// ���� �湮���� [x][y]�� ���� danji�� �� ���� �߰� 
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 1<=newx&&newx<=n&&1<=newy&&newy<=n ){
			if( area[newx][newy]==1 ){
				dfs(newx, newy, dnum);
			}
		}
	}
}

int main(){
	/* ������ ũ�� n�Է� */
	cin>>n;
	/* ������ ���� �Է� */
	// house�迭 0���� �ʱ�ȭ.
	fill_n(house, 25*25/2+1, 0);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%1d", &area[i][j]);
		}
	} 
	/* �� ���� �� ��� */
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if( area[i][j]==1 ){
				danji++;
				dfs(i, j, danji+1);
			}
		}
	}
	/* �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ���*/
	sort(house, house+danji);
	cout<<danji<<'\n';
	for(int i=0; i<danji; i++){
		cout<<house[i]<<'\n';
	}
	return 0;
}
