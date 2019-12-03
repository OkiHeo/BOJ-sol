#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// 컴퓨터의 수, 연결 쌍의 수, 1번 컴퓨터를 통해 감염되는 컴퓨터 수 
queue<int> q;		// bfs에 사용 
vector<int> node[101];		// n번 컴퓨터(1~100)의 연결상태 저장 
bool visit[101]={ false,};	// n번(1~100) 컴퓨터 방문여부 

void bfs(int start){
	// 탐색을 시작할 컴퓨터(1번) 방문처리 
	q.push(start);
	visit[start]=true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		// x번 컴퓨터에 연결되어있는 자식들 중 방문하지 않은것에 하나씩 방문 
		for(int i=0; i<node[x].size(); i++){
			int tmp = node[x][i];
			if( visit[tmp]==true ) continue;
			visit[tmp]=true;
			cnt++;
			q.push(tmp);
		}
	}
}

int main(){
	cin>>com>>net;
	
	// 컴퓨터를 잇는 네트워크 쌍을 입력받는다. 
	for(int i=1; i<=net; i++){
		int a, b;
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	// 각 컴퓨터에 연결된 네트워크를 순서대로 정렬 
	for(int i=1; i<=com; i++)
		sort(node[i].begin(), node[i].end());
		
	bfs(1);	// 1번 컴퓨터에서부터 탐색을 시작한다. 
	cout<<cnt;
	return 0;
}
