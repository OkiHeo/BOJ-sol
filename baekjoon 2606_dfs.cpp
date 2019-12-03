#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// 컴퓨터의 수, 연결 쌍의 수, 1번 컴퓨터를 통해 감염되는 컴퓨터 수 
vector<int> node[101];		// n번 컴퓨터(1~100)의 연결상태 저장 
bool visit[101]={ false,};	// n번(1~100) 컴퓨터 방문여부 

void dfs(int s){
	visit[s]=true;		// 매개변수로 주어진 컴퓨터 방문처리 
	
	// s에 연결되어있는 컴퓨터 중 방문하지 않은 컴퓨터 방문
	for(vector<int>::iterator i=node[s].begin(); i<node[s].end(); i++){
		if( visit[*i]==true) continue;
		visit[*i] = true;
		cnt++;
		dfs(*i);		// 연결되어있는 컴퓨터에 연결된 컴퓨터 재귀적으로 방문 
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
		
	dfs(1);	// 1번 컴퓨터에서부터 탐색을 시작한다. 
	cout<<cnt;
	return 0;
}
