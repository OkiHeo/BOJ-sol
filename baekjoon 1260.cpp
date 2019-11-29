#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> node[1001];	// 정점 최대 1000개
// dfs와 bfs에서 사용할 방문여부 체크 배열 
bool visitDfs[1001]={ false, };

queue<int> bfsQ;		// bfs결과를 순서대로 저장하기위한 큐 
bool visitBfs[1001]={ false, }; 

void dfs(int v, int cnt){
	int x=v;
	visitDfs[v] = true;
	printf("%d ", x);
	
	// N개 노드 모두 방문했다면 dfs함수 종료 
	if( cnt==N ){
		return;	
	}

	// node[v]에 연결된 노드 중 방문하지 않았던 노드들 반복적으로 방문. 
	for(vector<int>::iterator i=node[v].begin(); i<node[v].end(); i++){
		if( visitDfs[*i]==true ) continue;
		dfs(*i, cnt+1);
	}	
} 
void bfs(int v){
	// 처음에 방문하는 정점을 큐에 넣는다. 
	visitBfs[v] = true;
	bfsQ.push(v);
	
	// 큐가 빌 때까지 반복 
	while( !bfsQ.empty()){
		int x = bfsQ.front();		// 큐의 front에 있는 정점 정보 저장, 출력하고 pop 
		printf("%d ", x);
		bfsQ.pop();
		// 큐의 front에 있던 정점에 연결된 정점들 중 방문하지 않은 정점을 숫자가 작은 순서대로 큐에 저장 
		for(vector<int>::iterator i=node[x].begin(); i<node[x].end(); i++){
			int y = *i;
			if( visitBfs[y]==false ){
				bfsQ.push(y);
				visitBfs[y] = true;
			}
		}
	}
}
int main(){
	// 정점개수, 간선개수, 탐색 시작할 정점 번호 
	scanf("%d %d %d", &N, &M, &V);
	for(int i=1; i<=N; i++){
		node[i].push_back(i);
	}
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	// 각 노드의 연결상태 오름차순으로 정렬(맨 앞: 부모) 
	for(int i=1; i<=N; i++){
		sort(node[i].begin(), node[i].end());
	} 
	dfs(V,0);
	printf("\n");
	bfs(V);
	return 0;
}
