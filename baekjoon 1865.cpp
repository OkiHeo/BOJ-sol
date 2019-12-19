#include <iostream>
#include <vector>
using namespace std;

int tc, n, m, w;
int INF = 987654321;
int s[501];		// s[i]로 가는 최단시간 저장 
vector<pair<int,int> > p[501];
bool flag;		// 음의 사이클 발생 여부 

int main(){
	cin>>tc;
	while(tc--){
		// 음의 사이클 발생여부, 도로, 웜홀 연결들, s배열을 초기화해준다. 
		flag = false;
		for(int i=0; i<501; i++)
			p[i].clear();
		fill_n(s, n, INF);
		s[1] = 0;
		
		// 지점, 도로, 웜홀 개수 입력 
		cin>>n>>m>>w;
		// m개 도로 입력. 양방향. 
		for(int i=0; i<m; i++){
			int s, e, t;
			cin>>s>>e>>t;
			p[s].push_back(make_pair(e, t));
			p[e].push_back(make_pair(s, t));
		}
		// w개 웜홀 입력. 단방향. 음의 가중치.
		for(int i=0; i<w; i++){
			int s, e, t;
			cin>>s>>e>>t;
			p[s].push_back(make_pair(e, -t));
		}
		
		// 벨만 포드 알고리즘은 O(V*E)이다. 
		// 지점 개수 (V) 
		for(int i=1; i<=n; i++){
		// * 도로, 웜홀 개수(E) 
			for(int j=1; j<=n; j++){
				for(int k=0; k<p[j].size(); k++){
					int next = p[j][k].first;
					int cost = p[j][k].second;
					if( s[j]!=INF && s[next]>cost+s[j]){
						s[next] = cost + s[j];
						if( i==n ){
							// 음의 사이클 발생시 flag를 true로 한다. 
							flag = true;
						}
					}
				}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
