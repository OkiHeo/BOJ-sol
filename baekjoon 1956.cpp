#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
vector<pair<int, int> > city[401];

int main(){
	// 입력 
	int v, e;
	cin>>v>>e;
	for(int i=0; i<e; i++){
		int start, end, dist;
		cin>>start>>end>>dist;
		city[start].push_back(make_pair(end, dist));
	}
	
	/* 도로 길이의 합이 가장 작은 사이클을 찾고,
	   최소 사이클의 도로 길이의 합을 출력
	   운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력
	*/

	// s[i][j]에는 i도시에서 j도시로 가는 최단거리 저장 
	int s[v+1][v+1];
	// s 배열을 모두 INF로 초기화. 
	for(int i=0; i<=v; i++)
		fill_n(s[i], v+1, INF);
	
	// 입력받은 도시 간 연결 도로를 s에 저장한다. 
	for(int i=1; i<=v; i++){
		for(int j=0; j<city[i].size(); j++){
			s[i][city[i][j].first] = city[i][j].second;
		}
	}
	
	// i 도시에서 출발해서 k도시를 거쳐 j도시로 가는 최단거리 계산 
	for(int k=1; k<=v; k++){		// 노드 k를 거쳐간다! 
		for(int i=1; i<=v; i++){
			for(int j=1; j<=v; j++){
				// i에서 출발해서 k를 거쳐 j로 도착한다.
				if( s[i][k]==INF || s[k][j]==INF ) continue;
				if( s[i][k] + s[k][j] < s[i][j] ){
					s[i][j] = s[i][k] + s[k][j];
 				} 
			}
		}
	}
	
	// s[i][i]에는 i도시에서 출발해서 i도시로 도착하는 최단거리 저장.
	// s[i][i]를 0으로 초기화하지않고 INF로 초기화했으므로
	// 사이클이 형성되는 경우에만 i도시에서 출발해서
	// 돌아서 다시 i도시로 돌아오는 경우의 최단거리가 저장된다 
	int mincycle = 987654321;
	for(int i=1; i<=v; i++){
		mincycle = min( mincycle, s[i][i]);
	}
	
	// 도로 길이 합이 가장 작은 사이클의 도로 길이 합 mincycle 
	if( mincycle !=INF ){
		cout<<mincycle<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
	return 0; 
}
