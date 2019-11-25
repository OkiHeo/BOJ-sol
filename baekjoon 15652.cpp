#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int visit[9];
vector<int> v;

void dfs(int a, int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size()-1; i++){
			if( v[i]>v[i+1] ) return;		//비내림차순만 출력 
		}
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;		// 출력 후에는 dfs함수를 반드시 종료시켜야한다 
	}
	
	for(int i=a+1; i<=N; i++){
		if( visit[i]==M ) continue;	// 최대 M번까지 방문할 수 있도록 
		visit[i]++;
		v.push_back(i);
		dfs(a, cnt+1);
		visit[i]--;
		v.pop_back();
	}
}

int main(){
	cin>>N>>M;
	dfs(0, 0);
	return 0;
}  
