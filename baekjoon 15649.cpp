#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[9];
int cnt;
vector<int> v;

void dfs(int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=N; i++){
		// 앞서 방문했던 숫자는 방문x 
		if( visit[i] == true ){
			continue;
		}
		visit[i] = true;
		v.push_back(i);
		dfs(cnt+1);		//재귀함수로 구현한 DFS. i로 시작하는 이하 dfs 수행한다. 
		visit[i] = false;
		v.pop_back();
	}
}
int main(){
	cin>>N>>M;
	// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 모두 출력.
	dfs(0);
	return 0;
}
