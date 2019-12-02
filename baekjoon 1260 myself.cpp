#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> node[1001];		// 총 1000개의 정점 저장 가능. 인덱스 1~1000사용 
queue<int> bfsq;
bool visitDfs[1001]={ false,};
bool visitBfs[1001]={ false,};

void dfs(int v, int cnt){
	int x=v;
	visitDfs[v] = true;
	cout<<x<<' ';
	
	if( cnt==N ){
		cout<<'\n';
		return;
	}
	
	for(vector<int>::iterator i=node[v].begin(); i<node[v].end(); i++){
		if( visitDfs[*i]==true ) continue;
		dfs(*i, cnt+1);
	}
}
void bfs(int v){
	visitBfs[v] = true;
	bfsq.push(v);
	
	while(!bfsq.empty()){
		int x = bfsq.front();
		cout<<x<<' ';
		bfsq.pop();
		for(vector<int>::iterator i=node[x].begin(); i<node[x].end(); i++){
			if( visitBfs[*i]==true ) continue;
			visitBfs[*i] = true;
			bfsq.push(*i);
		}
	}
}

int main(){
	cin>>N>>M>>V;
	for(int i=1; i<=N; i++){
		node[i].push_back(i);
	}
	
	for(int i=1; i<=M; i++){
		int a, b;
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i=1; i<=N; i++){
		sort(node[i].begin(), node[i].end());
	}
	
	dfs(V, 0);
	cout<<'\n';
	bfs(V);
	return 0;
} 
