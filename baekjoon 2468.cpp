#include <iostream>
using namespace std;

int n;
int area[100][100];
bool visit[100][100];
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int max_height;
int max_safe=0;

void cal(int x, int y, int h){
	visit[x][y] = true;
	
	// �����¿�� ����Ǿ��ִ� �������� �湮üũ. 
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		// �����¿찡 ������ ����� ���� ���� üũ. 
		if( 0<=newx&&newx<n&&0<=newy&&newy<n) 
		if( area[newx][newy]>h && !visit[newx][newy] ){
			cal(newx, newy, h);
		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>area[i][j];
			max_height = max(max_height, area[i][j]);
		}
	}
	
	for(int h=0; h<=max_height; h++){
		// �� h���� visit�迭�� �ʱ�ȭ�����ش�. 
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				visit[i][j] = false;
		// �� �� �߻��ϴ� safe_area���� �ʱ�ȭ.
		int safe_area = 0;
		
		// ���������� ã���� �����¿� �湮üũ. 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if( area[i][j]>h && !visit[i][j] ){
					safe_area++;
					cal(i, j, h);
				}
			}
		}
		
		max_safe = max(max_safe, safe_area);
	}
	
	cout<<max_safe<<'\n';
	return 0;
} 
