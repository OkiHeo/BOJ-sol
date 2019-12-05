#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 200001
int V,E,K;
vector< pair<int, int> > node[20001];	// node[a]에 b, a-b가중치 
int shortest[20001];					// 시작정점~각정점까지의 최단거리 

void input(){
	scanf("%d %d", &V, &E);				// 정점 개수, 간선 개수 
	scanf("%d", &K);					// 시작 정점 
	for(int i=0; i<E; i++){
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);	// start->end 연결 가중치= cost 
		node[start].push_back(make_pair(cost, end));
		// 방향그래프이므로 start->end방향만 추가해주면 된다. 
	} 
} 

void dijkstra(int K){
	// 최단거리 무한대로 초기화 
	for(int i=1; i<=V; i++){
		shortest[i] = INF;
	}
	shortest[K] = 0; 
	priority_queue< pair<int, int> > pq;	// 시작~정점 최단거리, 정점 번호 넣는 우선순위큐 
	pq.push(make_pair(0,K));
	
	while(!pq.empty()){
		int dist = -pq.top().first;		// 시작-현재정점 최단거리 가장 작은 것 
		int cur = pq.top().second;			// 현재 정점.  
		pq.pop();
		
		// 시작~현재 최단거리가 시작~현재 가중치보다 작으면 패스! 
		if( shortest[cur]<dist ) continue;
		for(int i=0; i<node[cur].size(); i++){
			int nextDist = dist+node[cur][i].first;
			int next = node[cur][i].second;
			
			if( shortest[next] > nextDist ){
				shortest[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
				// 음수화해서 저장해야 시작~next정점까지의 거리가 제일 작은것을 먼저 pop할수있다. 
				// 우선 순위 큐는 최대 힙 구조이기 때문에. 
			}
		}
	}
}

int main(){
	input();
		
	dijkstra(K);
	
	for(int i=1; i<=V; i++){
		if( shortest[i]==INF )			// INF가 저장되어있으면 INF출력 
			printf("INF\n"); 
		else
			printf("%d\n", shortest[i]);	// 아니면 최단거리 출력 
	}
	return 0;
}
