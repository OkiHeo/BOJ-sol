#include <iostream>
using namespace std;

int n;
int graph[100][100];
int path[100][100];
bool visit[100];

void search(int i){
	// 정점 i에 연결된 정점들 중 방문하지 않은 정점을 방문. ( n level ) 
	for(int k=0; k<n; k++){
		if( graph[i][k] && !visit[k] ){
			visit[k] = true;		// 방문하지 않은 정점인 k를 방문처리하고 
			search(k);				// k에 연결된 방문하지 않은 정점을 방문. ( n+1 level ) 
		}
	}
}

int main(){
	// 입력 
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	
	// 경로 찾기 
	for(int i=0; i<n; i++){
		fill_n(visit, 100, 0);		// 매 정점 i를 탐색할 때마다 visit배열을 초기화해주어야한다. 
		search(i);
		
		// i정점에서 방문할 수 있는 정점들을 visit배열에서 알아내고, path에 추가. 
		for(int x=0; x<n; x++){
			if( visit[x] ){
				path[i][x] = 1;
			}
		}
	}
	
	// 찾은 경로 출력 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
} 
