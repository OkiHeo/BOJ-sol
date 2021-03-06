#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N, M, H;
int tomato[101][101][101];					//인덱스 1~1000 사용한다. 
queue <pair<pair<int, int>, int> > q;
int di[6][3] = {{0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}, {0,0,-1}, {0,0,1}};	// 상하좌우 검사를 위해 사용 

void input(){
	cin>>M>>N>>H;				// 가로길이(열), 세로 길이(행) 순서로 입력받는다. 
	for(int k=1; k<=H; k++)
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				cin>>tomato[i][j][k];
				// 입력받으면서 익은 토마토의 좌표를 큐에 저장한다.
				if( tomato[i][j][k]==1 ){				 
					q.push(make_pair(make_pair(i,j),k));
				}	
			}
		}
}

bool isIn(int x, int y, int z){
	return x>0&&x<=N&&y>0&&y<=M&&z>0&&z<=H;
}

int solve(){
	int x, y, z;
	for(int a=0; a<q.size(); a++){		// 처음에 입력받은 익은 토마토 각각에 대해 반복. 
		while(!q.empty()){
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			// 상하좌우 토마토를 검사한다. 
			for(int i=0; i<6; i++){
				int nx = x+di[i][0];
				int ny = y+di[i][1];
				int nz = z+di[i][2];
				// 범위 내에 존재 && 익지 않은 토마토라면
				// 이전 위치에서 하루 이후에 익음을 표시하고 큐에 push 한다. 
				if( isIn(nx, ny, nz)&&tomato[nx][ny][nz]==0 ){
					tomato[nx][ny][nz] = tomato[x][y][z]+1;
					q.push(make_pair(make_pair(nx, ny), nz));
				}
			}
		}
	} 
	// 모든 과정이 끝난 후 익지 않은 토마토가 있다면 -1 리턴. 아니면 day리턴 
	int day = 0;
	for(int k=1; k<=H; k++)
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				// 익지 않은 토마토가 남아있다면 -1을 출력한다. 
				if(tomato[i][j][k]==0) {
					return -1; 
				}
				day = max(day, tomato[i][j][k]-1);
					// 0일을 1일로 세므로 하루를 빼준다. 	
			}
		}
	return day;
} 

int main(){
	input();
	cout<<solve();
	return 0;
}
