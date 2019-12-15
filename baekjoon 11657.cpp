#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int> > city[501];		// city[1] ... city[500] 사용 
//city[i] -> B, time
int d[501];
int INF = 7000000;

void bellmanford(int start){
	// 시작 도시 제외한 다른 도시로 가는 시간 무한대로 초기화. 
	for(int i=1; i<=n; i++){
		d[i] = INF;
	}
	d[start] = 0;

	// dense graph를 가정하고 모든 노드간의 연결을 탐색한다. 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<city[j].size(); k++){
				int next = city[j][k].first;
				int connect = city[j][k].second;
				
				// d[j]가 INF가 아닐 때에만 간선 가중치와 더해서 업데이트 하는 것이 의미있다. 
				if( d[j]!=INF && d[next]>connect+d[j] ){
					// 최단 경로를 찾을 수 없어서 시작점으로 다시 돌아온 경우 
					if( i==n ){
						cout<<"-1\n";
						return;
					}
					d[next] = connect + d[j];
				}
			}
		}
	}
	
	// 1번도시에서 출발해서 i번째 도시로 가는 최단거리 출력. 
	for(int i=2; i<=n; i++){
		if( d[i]>=5000000 ){
			cout<<"-1\n";
		}else{
			cout<<d[i]<<'\n';
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int start, dest, time;
		cin>>start>>dest>>time;
		city[start].push_back(make_pair(dest, time));
	}
	
	/* 벨만 포드 알고리즘 실행 */
	bellmanford(1);
	return 0;
} 
