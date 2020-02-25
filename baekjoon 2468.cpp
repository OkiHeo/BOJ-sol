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
	
	// 상하좌우로 연결되어있는 안전영역 방문체크. 
	for(int v=0; v<4; v++){
		int newx = x+d[v][0];
		int newy = y+d[v][1];
		// 상하좌우가 영역을 벗어나지 않을 때만 체크. 
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
		// 매 h마다 visit배열을 초기화시켜준다. 
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				visit[i][j] = false;
		// 매 번 발생하는 safe_area개수 초기화.
		int safe_area = 0;
		
		// 안전영역을 찾으면 상하좌우 방문체크. 
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
