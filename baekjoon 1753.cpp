#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 200001
int V,E,K;
vector< pair<int, int> > node[20001];	// node[a]�� b, a-b����ġ 
int shortest[20001];					// ��������~������������ �ִܰŸ� 

void input(){
	scanf("%d %d", &V, &E);				// ���� ����, ���� ���� 
	scanf("%d", &K);					// ���� ���� 
	for(int i=0; i<E; i++){
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);	// start->end ���� ����ġ= cost 
		node[start].push_back(make_pair(cost, end));
		// ����׷����̹Ƿ� start->end���⸸ �߰����ָ� �ȴ�. 
	} 
} 

void dijkstra(int K){
	// �ִܰŸ� ���Ѵ�� �ʱ�ȭ 
	for(int i=1; i<=V; i++){
		shortest[i] = INF;
	}
	shortest[K] = 0; 
	priority_queue< pair<int, int> > pq;	// ����~���� �ִܰŸ�, ���� ��ȣ �ִ� �켱����ť 
	pq.push(make_pair(0,K));
	
	while(!pq.empty()){
		int dist = -pq.top().first;		// ����-�������� �ִܰŸ� ���� ���� �� 
		int cur = pq.top().second;			// ���� ����.  
		pq.pop();
		
		// ����~���� �ִܰŸ��� ����~���� ����ġ���� ������ �н�! 
		if( shortest[cur]<dist ) continue;
		for(int i=0; i<node[cur].size(); i++){
			int nextDist = dist+node[cur][i].first;
			int next = node[cur][i].second;
			
			if( shortest[next] > nextDist ){
				shortest[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
				// ����ȭ�ؼ� �����ؾ� ����~next���������� �Ÿ��� ���� �������� ���� pop�Ҽ��ִ�. 
				// �켱 ���� ť�� �ִ� �� �����̱� ������. 
			}
		}
	}
}

int main(){
	input();
		
	dijkstra(K);
	
	for(int i=1; i<=V; i++){
		if( shortest[i]==INF )			// INF�� ����Ǿ������� INF��� 
			printf("INF\n"); 
		else
			printf("%d\n", shortest[i]);	// �ƴϸ� �ִܰŸ� ��� 
	}
	return 0;
}
