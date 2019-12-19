#include <iostream>
using namespace std;

int n, m;
int path[101][101];
int INF = 100000000;

void init(){
	// 모든 경로를 INF로 초기화한다. 
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			path[i][j] = INF;
			// 자기 자신으로 가는 거리는 0
			if( i==j ) path[i][j] = 0;
		}
	}
}

void floyd(){
	// 플로이드 와샬 알고리즘 시작 
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){		// i에서 출발 
			for(int j=1; j<=n; j++){	// j로 도착하는데, k를 경유한다. 
				// 경유거리 중 무한대가 없을때만 경유함 
				if( path[i][k]!=INF && path[k][j]!=INF ) 
					path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	init();
	// 버스 출발지, 도착지, 걸리는 시간 입력. 
	for(int i=0; i<m; i++){
		int s, e, d;
		cin>>s>>e>>d;
		// path 배열 업데이트 
		// 연결된 간선 중 가장 짧은 것으로 업데이트하자 
		path[s][e] = min(path[s][e], d);
	}
	floyd();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(path[i][j]==INF || path[i][j]==0)
				cout<<0<<' ';
			else
				cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
