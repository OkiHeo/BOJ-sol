#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> node[1001];	// ���� �ִ� 1000��
// dfs�� bfs���� ����� �湮���� üũ �迭 
bool visitDfs[1001]={ false, };

queue<int> bfsQ;		// bfs����� ������� �����ϱ����� ť 
bool visitBfs[1001]={ false, }; 

void dfs(int v, int cnt){
	int x=v;
	visitDfs[v] = true;
	printf("%d ", x);
	
	// N�� ��� ��� �湮�ߴٸ� dfs�Լ� ���� 
	if( cnt==N ){
		return;	
	}

	// node[v]�� ����� ��� �� �湮���� �ʾҴ� ���� �ݺ������� �湮. 
	for(vector<int>::iterator i=node[v].begin(); i<node[v].end(); i++){
		if( visitDfs[*i]==true ) continue;
		dfs(*i, cnt+1);
	}	
} 
void bfs(int v){
	// ó���� �湮�ϴ� ������ ť�� �ִ´�. 
	visitBfs[v] = true;
	bfsQ.push(v);
	
	// ť�� �� ������ �ݺ� 
	while( !bfsQ.empty()){
		int x = bfsQ.front();		// ť�� front�� �ִ� ���� ���� ����, ����ϰ� pop 
		printf("%d ", x);
		bfsQ.pop();
		// ť�� front�� �ִ� ������ ����� ������ �� �湮���� ���� ������ ���ڰ� ���� ������� ť�� ���� 
		for(vector<int>::iterator i=node[x].begin(); i<node[x].end(); i++){
			int y = *i;
			if( visitBfs[y]==false ){
				bfsQ.push(y);
				visitBfs[y] = true;
			}
		}
	}
}
int main(){
	// ��������, ��������, Ž�� ������ ���� ��ȣ 
	scanf("%d %d %d", &N, &M, &V);
	for(int i=1; i<=N; i++){
		node[i].push_back(i);
	}
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	// �� ����� ������� ������������ ����(�� ��: �θ�) 
	for(int i=1; i<=N; i++){
		sort(node[i].begin(), node[i].end());
	} 
	dfs(V,0);
	printf("\n");
	bfs(V);
	return 0;
}
