#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// 컴퓨터의 수, 연결 쌍의 수, 1번 컴퓨터를 통해 감염되는 컴퓨터 수 
vector<int> node[101];		// n번 컴퓨터(1~100)의 연결상태 저장 
bool visit[101]={ false,};	// n번(1~100) 컴퓨터 방문여부 

void dfs(int s){
	visit[s]=true;
	
	for(vector<int>::iterator i=node[s].begin(); i<node[s].end(); i++){
		if( visit[*i]==true) continue;
		visit[*i] = true;
		cnt++;
		dfs(*i);
	}
}

int main(){
	cin>>com>>net;
	for(int i=0; i<=com; i++){
		node[i].push_back(i);
	}
	
	for(int i=1; i<=net; i++){
		int a, b;
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i=1; i<=com; i++)
		sort(node[i].begin(), node[i].end());
		
	dfs(1);
	cout<<cnt;
	return 0;
}
