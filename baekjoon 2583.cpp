#include <iostream>
#include <algorithm>
using namespace std;

int m, n, k;		// 모두 100이하의 자연수 
int paper[101][101];	// (0,0)~(n,m)이 존재하므로 n,m의 최댓값인 100까지는 수용해야한다. 
int area[101*101/2+1];		// [1]~[areaNum]에 저장된다. 
int areaNum=0;
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
int square[100][4];

void dfs(int x, int y, int aN){
	paper[x][y] = aN+2;		// 이미 숫자를 센 빈 공간에는 aN+2를 저장해서 다시 찾지 않도록. 
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
	/* m, n, k 입력 */
	cin>>m>>n>>k;
	/* k개의 직사각형 좌하(a, b), 우상단(c, d) 좌표 입력 */
	for(int i=0; i<k; i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		// 직사각형을 1로 마킹해주자. 
		for(int p=a; p<c; p++){
			for(int q=b; q<d; q++){
				paper[p][q]=1;
			}
		}
	}

	/* 나눠진 영역의 개수를 세고, 각 영역의 넓이를 계산한다. */
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if( paper[i][j]==0 ){
				areaNum++;
				dfs(i, j, areaNum);
			}
		}
	}
	
	/* 분리되어 나누어지는 영역의 개수 출력 */
	cout<<areaNum<<'\n';
	
	/* 각 영역의 넓이 오름차순으로 정렬하여 빈칸을 사이에 두고 출력 */
	sort(area+1, area+areaNum+1);	// 1번인덱스~areaNum인덱스까지 정렬 
	for(int i=1; i<=areaNum; i++){	// 1번인덱스~areaNum인덱스까지 출력 
		cout<<area[i]<<' ';
	}
	return 0;
}
 
