#include <iostream>
#include <algorithm>
using namespace std;

int m, n, k;		// ��� 100������ �ڿ��� 
int paper[101][101];	// (0,0)~(n,m)�� �����ϹǷ� n,m�� �ִ��� 100������ �����ؾ��Ѵ�. 
int area[101*101/2+1];		// [1]~[areaNum]�� ����ȴ�. 
int areaNum=0;
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
int square[100][4];

void dfs(int x, int y, int aN){
	paper[x][y] = aN+2;		// �̹� ���ڸ� �� �� �������� aN+2�� �����ؼ� �ٽ� ã�� �ʵ���. 
	area[aN]++;
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 0<=newx&&newx<n&&0<=newy&&newy<m )
		if( paper[newx][newy]==0 ){
			dfs(newx, newy, aN);
		}
	}
}

int main(){
	/* m, n, k �Է� */
	cin>>m>>n>>k;
	/* k���� ���簢�� ����(a, b), ����(c, d) ��ǥ �Է� */
	for(int i=0; i<k; i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		// ���簢���� 1�� ��ŷ������. 
		for(int p=a; p<c; p++){
			for(int q=b; q<d; q++){
				paper[p][q]=1;
			}
		}
	}

	/* ������ ������ ������ ����, �� ������ ���̸� ����Ѵ�. */
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if( paper[i][j]==0 ){
				areaNum++;
				dfs(i, j, areaNum);
			}
		}
	}
	
	/* �и��Ǿ� ���������� ������ ���� ��� */
	cout<<areaNum<<'\n';
	
	/* �� ������ ���� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ��� */
	sort(area+1, area+areaNum+1);	// 1���ε���~areaNum�ε������� ���� 
	for(int i=1; i<=areaNum; i++){	// 1���ε���~areaNum�ε������� ��� 
		cout<<area[i]<<' ';
	}
	return 0;
}
 
