#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > p[501];
int testcase, point, road, worm;
int time[501];
int INF = 2000000000;

bool travel(){
	for(int i=1; i<=point; i++){
		for(int j=1; j<=point; j++){
			for(int k=0; k<p[j].size(); k++){
				int next = p[j][k].first;
				int takes = p[j][k].second+time[j];
				
				if( time[j]!=INF && takes<time[next] ){
					if( i==point ){
						return true;
					}
					time[next] = takes;
				}
			}
		}
	}
	return false;
}

int main(){
	cin>>testcase;
	for(int tc=0; tc<testcase; tc++){
        // 1번 지점에서 각 지점으로 가는데 걸리는 시간 무한대로 초기화 
		for(int init=0; init<501; init++){
			time[init] = INF;
		}
		// 시작 지점에서 시작지점으로 가는 시간은 0이다. 
		time[1] = 0;
        for(int i=0; i<501; i++){
            p[i].clear();
        }
        
        // 입력
		cin>>point>>road>>worm;
		for(int r=0; r<road; r++){
			int s, e, t;
			cin>>s>>e>>t;
			// 도로는 양방향(=무방향)이다. 
			p[s].push_back(make_pair(e, t));
			p[e].push_back(make_pair(s, t));
		}
		for(int w=0; w<worm; w++){
			int s, e, d;
			cin>>s>>e>>d;
			// 웜홀은 단방향이다.
			// 웜홀에서는 시간이 거꾸로 흐르므로 -d로 저장해준다. 
			p[s].push_back(make_pair(e, -d));
		}
		// 음의 사이클이 존재하면 yes
		// (음의 사이클 중 하나에서 출발하면 출발지로 돌아오면 과거가 된다.)
		if( travel() ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
