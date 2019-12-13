#include <iostream>
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 2000000000;
int T;				// �׽�Ʈ���̽����� 
int n, m, t;		// ���ð���, ���ΰ���, �������ĺ����� 
int s, g, h;		// �����, ������1, ������2 
vector<pair<int, int> > city[2001];		// ���� �� ���� ���� 
vector<int> dest;						// ������ �ĺ��� ����

vector<int> dijkstra(int start){
	priority_queue<pair<int, int> > pq;
	// -�Ÿ�, ���ù�ȣ, �� ������ ���� ���� ����.
	vector<int> shortest(n+1, INF);
	// ���-��߰Ÿ� :0, �������, ������ ���� ���� �������� ť�� push 
	pq.push(make_pair(0, start));
	shortest[start] = 0;
	
	while(!pq.empty()){
		int now = pq.top().second;
		int di = -pq.top().first;
		pq.pop();
		
		if( shortest[now] < di ) continue;
		// ���� ������ ����� �� ���ʷ� �湮. 
		for(int i=0; i<city[now].size(); i++){
			int next = city[now][i].first;
			int nextDist = city[now][i].second+di;
			
			// �������->now->next �����ϴ� ���ΰ� �˰��ִ� �ִܰ�κ��� ª�� ��� ����. 
			if( shortest[next] >= nextDist ){
				shortest[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	// start���� �ٸ� ��� ���������� �ִܰŸ��� ���� ���͸� ����. 
	return shortest;
}

int main(){
	scanf("%d", &T);		// �׽�Ʈ���̽� �Է�
	for(int i=0; i<T; i++){
	 	/*init*/
	 	for(int i=0; i<2001; i++){
	 		city[i].clear();
		}
		dest.clear(); 
		/*input*/
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		// m���� ���� �Է�. 
		for(int i=0; i<m; i++){
			int start, end, dist;
			scanf("%d %d %d", &start, &end, &dist);
			city[start].push_back(make_pair(end, dist));
			city[end].push_back(make_pair(start, dist));
		}
		// t���� ������ �ĺ� �Է�. 
		for(int i=0; i<t; i++){
			int x;
			scanf("%d", &x);
			dest.push_back(x);
		}
		// ������ �ĺ����� ������������ ����
		sort(dest.begin(), dest.end());
		
		/*solve*/
		vector<int> sS = dijkstra(s);
		vector<int> sG = dijkstra(g);
		vector<int> sH = dijkstra(h);
		
		// ����~������ �ĺ������� �ִܰŸ��� s-g-h-t �Ǵ� s-h-g-t��� �������� ��� �������Ƿ� ����Ѵ�. 
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
