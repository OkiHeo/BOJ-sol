#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tc, n, m, k;
vector<pair<int, pair<int, int> > > air[101];		// �ε��� 1~100 ��� 
// air[��߰���]�� ��������, ���, �ҿ�ð� ����. 
priority_queue<pair<int,pair<int, int> > > pq;
int path[101][10001];
// 1������ i�� ���� �ּ� Ƽ�ϰ���1~10000�� ���� �̵��ð�[i][1~10000] ����. 
// ���� ���� �� cost�� ���ؼ� �̵��ð��� ����ϰ�, n��° ������ �� cost�� ���� �̵��ð� �� �ִܽð��� ���� 
int INF = 987654321;

int main(){
	cin>>tc;
	while(tc--){
		// air ���Ϳ� path�迭 �ʱ�ȭ
		for(int i=0; i<101; i++){
			air[i].clear();
			fill_n(path[i], 10001, INF);
		}
		path[1][0] = 0;		// ��õ�� ������ �ε��� 1, ��� cost �� ���� 0 
		
		// �Է�
		cin>>n>>m>>k;
		for(int i=0; i<k; i++){
			int start, dest, cost, time;
			cin>>start>>dest>>cost>>time;
			air[start].push_back(make_pair(dest, make_pair(cost, time)));
		}
		// 1���� ���� ��� ����ȭ�� ��, 1���� ���� �ִܽð�, ��߰��� ��ȣ 1 
		pq.push(make_pair(0,make_pair(0, 1)));
		
		while(!pq.empty()){
			int nowcost = -pq.top().first;
			int nowtime = pq.top().second.first;
			int now = pq.top().second.second;
			pq.pop(); 
			
			if( path[now][nowcost] < nowtime ) continue;
			for(int i=0; i<air[now].size(); i++){
				int next = air[now][i].first;
				int nextcost = air[now][i].second.first+nowcost;
				int nexttime = air[now][i].second.second+nowtime;
				 
				// 1~now ��� + now~next ��� <= ����(m) �� ��
				// �ҿ�ð��� ����ȴٸ� ������Ʈ �Ѵ�.
				if( nextcost <= m ){
					if( nexttime < path[next][nextcost] ){
						path[next][nextcost] = nexttime;
						pq.push(make_pair(-nextcost, make_pair(nexttime, next)));
					}
				}
			}
		} 
		
		int mintime=INF;
		for(int i=0; i<=m; i++){
			mintime = min(mintime,path[n][i]);
		}
		if( mintime!=INF ){
			cout<<mintime<<'\n';
		}
		else{
			cout<<"Poor KCM\n";
		}
	}
	return 0; 
}
