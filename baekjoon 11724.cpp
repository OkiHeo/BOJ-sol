#include <iostream>
using namespace std;

int n, m;
int graph[1000][1000];
bool visit[1000];

void dfs(int now){
	visit[now] = true;		// now에 방문표시. 
	// now의 인접정점들 중 방문하지않은것들에 방문한다. 
	for(int i=0; i<n; i++){
		if( graph[now][i] && !visit[i]){
			// now와 i간의 연결이 존재 && i에 방문한 적 없을때
			dfs(i);
		}
	}
}

int main(){
	/* 정점의 개수 n, 간선의 개수 m 입력 */
	cin>>n>>m;
	for(int input=0; input<m; input++){
		int from, to;
		cin>>from>>to;
		// from과 to에 각각 -1을 하는 이유는 나는 인덱스 0부터 사용했기 때문
		// 1번 정점의 인덱스는 0이다. 
		graph[from-1][to-1] = graph[to-1][from-1] = 1;		// 무방향 그래프 설정 
	} 
	
	/* 연결요소 탐색 */
	int cnt=0;
	for(int i=0; i<n; i++){
		if( visit[i] ) continue;
		dfs(i);
		cnt++;
	} 
	cout<<cnt<<'\n';
	return 0;
}
