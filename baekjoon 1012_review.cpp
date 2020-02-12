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
		// 새로운 위치가 밭 내부에 존재하고 
		if( 0<=newx && newx<=M-1 && 0<=newy && newy<=N-1 ){
			// 새로운 위치가 배추이며, 방문하지 않은 배추일 때 
			if( ground[newx][newy]==1 && visit[newx][newy]==false ){
				visit[newx][newy] = true;		// 방문표시
				dfs(newx, newy); 
			}
		}
	}
}

int main(){
	/* 테스트 케이스의 개수 T입력 */
	cin>>T;
	for(int t=0; t<T; t++){
		/* 배추를 심은 배추밭의 가로 길이 M, 세로길이 N, 배추 개수 K개 입력*/
		cin>>M>>N>>K;
		// 배추밭 0, visit배열 false로 초기화.
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				ground[i][j] = 0;
				visit[i][j] = false;
			}
		} 
		/* 배추의 위치 x,y좌표 K개 입력 */
		for(int k=0; k<K; k++){
			int x, y;
			cin>>x>>y;
			ground[x][y] = 1;
		}
		
		/* 각 케이스에 대해 필요한 최소의 배추지렁이 마리 수를 출력*/
		int cnt=0;
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				if( ground[i][j]==1 && visit[i][j]==false ){
					cnt++;
					// 그 배추에 연결된 배추들은 방문처리한다.
					dfs(i, j); 
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
