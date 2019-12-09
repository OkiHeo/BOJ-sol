#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, E;
int one, two;
vector< pair<int, int> > node[801];
int INF = 800001;

void input(){
	//  정점의 개수, 간선의 개수 입력 
	scanf("%d %d", &N, &E);
	// 그래프 입력 
	for(int i=0; i<E; i++){
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		// 양방향 그래프! 
		node[start].push_back(make_pair(end, cost));
		node[end].push_back(make_pair(start, cost));
	}
	// 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 
	scanf("%d %d", &one, &two);
}

vector<int> dijkstra(int start){
	// start 에서 시작해서 각 정점으로 가는 최단거리 무한대로 초기화. 
// vector를 리턴하도록 수정해보았다. 
	vector<int> shortest(801, INF);
	
	priority_queue< pair<int, int> > pq;
	// 우선순위 큐에 시작 정점 push.  
	pq.push(make_pair(0, start));
	shortest[start] = 0; 
	
	while(!pq.empty()){
		// 현재 위치의 정점에 대해 탐색. 
		int now = pq.top().second;
		int nowcost = -pq.top().first;
		pq.pop();
		// 알고 있는 start->now 최단거리보다 nowcost가 크면 이 정점은 패스 
		if( shortest[now] < nowcost ) continue;
		
		// now를 경유해서 갈 수 있는 정점에 경유해서 가는 거리가 더 짧다면 교체. 
		for( int i=0; i<node[now].size(); i++){
			int next = node[now][i].first;
			int nextcost = node[now][i].second + nowcost;
			
			if( shortest[next] > nextcost ){
				shortest[next] = nextcost;
				pq.push(make_pair(-nextcost, next));
				// 우선순위 큐를 사용하므로 cost를 음수화해서 저장해야 작은것부터 꺼낼 수 있다. 
			}
		}
	}
// start부터 다른 모든 정점으로의 최단거리를 저장한 벡터자체를 리턴함. 
	return shortest;
}

int solve(){
	vector<int> sStart = dijkstra(1);
	int startToOne = sStart[one];
	int startToTwo = sStart[two];
	
	vector<int> sOne = dijkstra(one);
	int oneToTwo = sOne[two];
	// one->two와 two->one은 동일하므로 한번만 사용. 
	
	vector<int> sEnd = dijkstra(N);
	int twoToEnd = sEnd[two];
	int oneToEnd = sEnd[one];

	// 두 가지 경로의 결과값 저장. 
	int result1=0, result2=0;	
	result1 = startToOne+oneToTwo+twoToEnd;		// 경로1번 결과 
	result2 = startToTwo+oneToTwo+oneToEnd;		// 경로2번 결과 
	
//수정한 부분! 
	int result = min(result1, result2);
	if( result>=INF )	return -1;
	else return result;
}

int main(){
	input();
	printf("%d\n", solve());
	return 0;
}
