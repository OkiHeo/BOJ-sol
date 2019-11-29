#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v[101];	// �� ��ǻ��[i] �� ������� ����
bool visit[101] = {false,};	// [i]��ǻ�͸� �湮�ߴ��� ǥ��
int num=0;		// 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� ��ǻ�� ��

void dfs(int n){
	visit[n] = true;
	// n�� ��ǻ�Ϳ� ����� ��ǻ�͵� �湮.
	for(int i=1; i<=v[n].size(); i++){
		if(visit[i]==true) continue;	// �湮�ߴ� ��ǻ�ʹ� pass 
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
