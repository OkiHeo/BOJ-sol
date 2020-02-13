#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/*2667 단지번호붙이기 dfs로 풀어보자*/

int n;
int danji=0, house[25*25/2+1];
int area[26][26];
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int x, int y, int dnum){
	area[x][y] = dnum;
	house[dnum-2]++;		// 현재 방문중인 [x][y]의 수를 danji의 집 수에 추가 
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
	/* 지도의 크기 n입력 */
	cin>>n;
	/* 지도의 내용 입력 */
	// house배열 0으로 초기화.
	fill_n(house, 25*25/2+1, 0);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%1d", &area[i][j]);
		}
	} 
	/* 총 단지 수 계산 */
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if( area[i][j]==1 ){
				danji++;
				dfs(i, j, danji+1);
			}
		}
	}
	/* 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력*/
	sort(house, house+danji);
	cout<<danji<<'\n';
	for(int i=0; i<danji; i++){
		cout<<house[i]<<'\n';
	}
	return 0;
}
