#include <iostream>
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 2000000000;
int T;				// 테스트케이스개수 
int n, m, t;		// 도시개수, 도로개수, 목적지후보개수 
int s, g, h;		// 출발지, 경유지1, 경유지2 
vector<pair<int, int> > city[2001];		// 도시 간 연결 저장 
vector<int> dest;						// 목적지 후보들 저장

vector<int> dijkstra(int start){
	priority_queue<pair<int, int> > pq;
	// -거리, 도시번호, 두 경유지 경유 여부 저장.
	vector<int> shortest(n+1, INF);
	// 출발-출발거리 :0, 출발지점, 경유지 사이 도로 지났는지 큐에 push 
	pq.push(make_pair(0, start));
	shortest[start] = 0;
	
	while(!pq.empty()){
		int now = pq.top().second;
		int di = -pq.top().first;
		pq.pop();
		
		if( shortest[now] < di ) continue;
		// 현재 지점에 연결된 곳 차례로 방문. 
		for(int i=0; i<city[now].size(); i++){
			int next = city[now][i].first;
			int nextDist = city[now][i].second+di;
			
			// 출발지점->now->next 경유하는 도로가 알고있는 최단경로보다 짧은 경우 갱신. 
			if( shortest[next] >= nextDist ){
				shortest[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	// start에서 다른 모든 정점으로의 최단거리를 담은 벡터를 리턴. 
	return shortest;
}

int main(){
	scanf("%d", &T);		// 테스트케이스 입력
	for(int i=0; i<T; i++){
	 	/*init*/
	 	for(int i=0; i<2001; i++){
	 		city[i].clear();
		}
		dest.clear(); 
		/*input*/
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		// m개의 도로 입력. 
		for(int i=0; i<m; i++){
			int start, end, dist;
			scanf("%d %d %d", &start, &end, &dist);
			city[start].push_back(make_pair(end, dist));
			city[end].push_back(make_pair(start, dist));
		}
		// t개의 목적지 후보 입력. 
		for(int i=0; i<t; i++){
			int x;
			scanf("%d", &x);
			dest.push_back(x);
		}
		// 목적지 후보들을 오름차순으로 정렬
		sort(dest.begin(), dest.end());
		
		/*solve*/
		vector<int> sS = dijkstra(s);
		vector<int> sG = dijkstra(g);
		vector<int> sH = dijkstra(h);
		
		// 시작~목적지 후보까지의 최단거리가 s-g-h-t 또는 s-h-g-t라면 경유지를 모두 지났으므로 출력한다. 
		for(int i=0; i<dest.size(); i++){
			int sght = sG[s]+sG[h]+sH[dest[i]];
			int shgt = sH[s]+sH[g]+sG[dest[i]];
			int st = sS[dest[i]];
			if( st==sght || st==shgt ){
				printf("%d ", dest[i]);
			}
		}
		printf("\n");
	} 
	return 0;
}
