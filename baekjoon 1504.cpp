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

int dijkstra(int start, int end){
	// start 에서 시작해서 각 정점으로 가는 최단거리 무한대로 초기화. 
	long long int shortest[801];
	fill_n(shortest, 801, INF);
	
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

	// end까지의 최단거리 갱신이 안되었다면 -1을 리턴한다. 
	if( shortest[end] >= INF ) return -1;
	// end까지의 최단거리가 존재한다면 그 거리를 리턴 
	else	return shortest[end];
}

int solve(){
	int startToOne = dijkstra(1, one);
	int startToTwo = dijkstra(1, two);
	int oneToTwo = dijkstra(one, two);
	int twoToEnd = dijkstra(two, N);
	int oneToEnd = dijkstra(one, N);
	int result1=0, result2=0;
	bool flag1 = true, flag2 = true;
	// 경로 중 하나라도 최단거리를 찾지 못하는 경로가 있다면 -1을 출력한다. 
	// 경로 1번 : 1->one->two->N
	if( startToOne==-1 || oneToTwo==-1 || twoToEnd==-1 ){
		flag1 = false;
	}
	// 경로 2번 : 1->two->one->N
	if( startToTwo==-1 || oneToTwo==-1 || oneToEnd==-1 ){
		flag2 = false;
	}

	result1 = startToOne+oneToTwo+twoToEnd;		// 경로1번 결과 
	result2 = startToTwo+oneToTwo+oneToEnd;		// 경로2번 결과 

	// 경로 1번, 경로 2번 모두 불가능 할 때 
	if( !flag1 && !flag2 ){
		return -1; 
	}
	// 경로 1만 가능할때 
	else if( flag1 && !flag2 ){
		return result1;
	}
	// 경로 2만 가능할때 
	else if( flag2 && !flag1){
		return result2;
	}
	// 경로 1과 2 모두 가능할 때 
	else{
		return min(result1, result2);
	}
}
int main(){
	input();
	printf("%d\n", solve());
	return 0;
}
