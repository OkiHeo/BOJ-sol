#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tc, n, m, k;
vector<pair<int, pair<int, int> > > air[101];		// 인덱스 1~100 사용 
// air[출발공항]에 도착공항, 비용, 소요시간 저장. 
priority_queue<pair<int,pair<int, int> > > pq;
int path[101][10001];
// 1번에서 i로 가는 최소 티켓가격1~10000에 따른 이동시간[i][1~10000] 저장. 
// 예산 내의 각 cost에 대해서 이동시간을 계산하고, n번째 공항의 각 cost에 따른 이동시간 중 최단시간을 고르자 
int INF = 987654321;

int main(){
	cin>>tc;
	while(tc--){
		// air 벡터와 path배열 초기화
		for(int i=0; i<101; i++){
			air[i].clear();
			fill_n(path[i], 10001, INF);
		}
		path[1][0] = 0;		// 인천은 언제나 인덱스 1, 모든 cost 에 대해 0 
		
		// 입력
		cin>>n>>m>>k;
		for(int i=0; i<k; i++){
			int start, dest, cost, time;
			cin>>start>>dest>>cost>>time;
			air[start].push_back(make_pair(dest, make_pair(cost, time)));
		}
		// 1으로 가는 비용 음수화한 것, 1으로 가는 최단시간, 출발공항 번호 1 
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
				 
				// 1~now 비용 + now~next 비용 <= 예산(m) 일 때
				// 소요시간이 단축된다면 업데이트 한다.
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
