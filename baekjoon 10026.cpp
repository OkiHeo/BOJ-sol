#include <iostream>
using namespace std;

int n;
char pic[101][101];
bool visit[101][101];
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int rgb=0, nonrgb=0;

void RGBpeople(int x, int y, char now){
	visit[x][y] = true;
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 0<=newx&&newx<n && 0<=newy&&newy<n ){
			if( visit[newx][newy]==true ) continue;		// �̹� �湮�ߴ� ������ �н� 
			// ���� Ž������ ���� �����¿� ��ġ�� ���� ������ 
			if( now==pic[newx][newy] )
				RGBpeople(newx, newy, now);
		}
	}
}

void nonRGBpeople(int x, int y, char now){
	visit[x][y] = true;
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		if( 0<=newx&&newx<n && 0<=newy&&newy<n ){
			if( visit[newx][newy]==true) continue;		// �湮�ߴ� ������ �н� 
			// ���� Ž������ ���� 'R' �Ǵ� 'G'�� �� 
			if( now=='R'||now=='G'){
				if(pic[newx][newy]=='R'){
					nonRGBpeople(newx, newy, 'R');
				}
				else if(pic[newx][newy]=='G'){
					nonRGBpeople(newx, newy, 'G');
				}
			}
			// ���� Ž������ ���� 'B'�� �� 
			else{
				// �����¿찡 ���� Ž������ ���� ������ 
				if( now==pic[newx][newy] )
					nonRGBpeople(newx, newy, now);
			}
		}
	}
}

int main(){
	/* �׸��� �Է����� �־��� */
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>pic[i];
	}

	/* ���ϻ����� �ƴ� ����� ���� �� ������ �� ���ϱ� */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( visit[i][j]==false ){
				rgb++;
				RGBpeople(i, j, pic[i][j]);
			}
		}
	}
	
	/* visit �迭 �ʱ�ȭ */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			visit[i][j] = false;
		}
	}
	
	/* ���ϻ����� ����� ���� �� ������ �� ���ϱ� */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( visit[i][j]==false ){
				nonrgb++;
				nonRGBpeople(i, j, pic[i][j]);
			}
		}
	}
	
	cout<<rgb<<' '<<nonrgb<<'\n';
	return 0;
}
