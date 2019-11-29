#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[101];	// 각 컴퓨터[i] 의 연결상태 저장
bool visit[101] = {false,};	// [i]컴퓨터를 방문했는지 표시
int num=0;		// 1번 컴퓨터를 통해 웜 바이러스에 걸리는 컴퓨터 수

void dfs(int n){
	visit[n] = true;
	// n번 컴퓨터에 연결된 컴퓨터들 방문.
	for(int i=1; i<=v[n].size(); i++){
		if(visit[i]==true) continue;	// 방문했던 컴퓨터는 pass 
		visit[i] = true;
		num++;
		dfs(i);
	}
} 

int main(){
	scanf("%d\n%d", &N, &M);
	for(int i=1; i<=N; i++){
		v[i].push_back(i);
	}
	
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1; i<=N; i++){
		sort(v[i].begin()+1, v[i].end());
	}
	
	dfs(1);
	printf("%d", num);
	return 0;
} 
