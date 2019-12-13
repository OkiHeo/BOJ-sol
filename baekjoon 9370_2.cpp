#include <iostream>
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n, m, t;
int s, g, h;
int INF = 2000000000;
vector< pair<int, int> > city[2001];	// �ε��� 1~n�� ����Ѵ�. 
vector<int> dest;	//������ �ĺ� ����

vector<int> dijkstra(int start){
	vector<int> shortest(n+1, INF);		// �ε��� 1~n�� ���. 
	shortest[start] = 0;
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()){
		int now = pq.top().second;
		int nowcost = -pq.top().first;
		pq.pop();
		
		for(int i=0; i<city[now].size(); i++){
			int next = city[now][i].first;
			int nextcost = nowcost + city[now][i].second;
			if( shortest[next] > nextcost ){
				shortest[next] = nextcost;
				pq.push(make_pair(-nextcost, next));
			}
		}
	}
	return shortest;
}

int main(){
	cin>>T;
	for(int i=0; i<T; i++){
		/*init & input*/
		for(int i=0; i<2001; i++)
			city[i].clear();
		dest.clear();
		cin>>n>>m>>t;
		cin>>s>>g>>h;
		for(int i=0; i<m; i++){
			int a, b, d;
			cin>>a>>b>>d;
			city[a].push_back(make_pair(b, d));
			city[b].push_back(make_pair(a, d));
		}
		for(int i=0; i<t; i++){
			int x;
			cin>>x;
			dest.push_back(x);
		}
		
		/*solve*/
		// ������ �ĺ����� �������� �����Ѵ�. 
		sort(dest.begin(), dest.end());
		vector<int> startG = dijkstra(g);
		vector<int> startH = dijkstra(h);
		vector<int> startS = dijkstra(s);
		
		int sgh = startG[s]+startG[h];
		int shg = startH[s]+startG[h];
		for(int i=0; i<dest.size(); i++){
			int cur = dest[i];
			int sght = sgh+startH[cur];
			int shgt = shg+startG[cur];
			int st = startS[cur];
			if( sght==st){
				printf("%d ", cur);
			}
			else if (shgt==st){
				printf("%d ", cur);
			}
		}
		printf("\n");
	}
} 
