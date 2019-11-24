#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
bool visit[9];

void dfs(int idx, int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
	}
	
	for(int i=idx+1; i<=N; i++){
		if( visit[i] == true ){
			continue;
		}
		visit[i] = true;
		v.push_back(i);
		dfs(i, cnt+1);
		visit[i] = false;
		v.pop_back();
	}
}
int main(){
	cin>>N>>M;
	dfs(0, 0);
	return 0;
}
