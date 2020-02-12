#include <iostream>
using namespace std;

int n, m;
int graph[1000][1000];
bool visit[1000];

void dfs(int now){
	visit[now] = true;		// now�� �湮ǥ��. 
	// now�� ���������� �� �湮���������͵鿡 �湮�Ѵ�. 
	for(int i=0; i<n; i++){
		if( graph[now][i] && !visit[i]){
			// now�� i���� ������ ���� && i�� �湮�� �� ������
			dfs(i);
		}
	}
}

int main(){
	/* ������ ���� n, ������ ���� m �Է� */
	cin>>n>>m;
	for(int input=0; input<m; input++){
		int from, to;
		cin>>from>>to;
		// from�� to�� ���� -1�� �ϴ� ������ ���� �ε��� 0���� ����߱� ����
		// 1�� ������ �ε����� 0�̴�. 
		graph[from-1][to-1] = graph[to-1][from-1] = 1;		// ������ �׷��� ���� 
	} 
	
	/* ������ Ž�� */
	int cnt=0;
	for(int i=0; i<n; i++){
		if( visit[i] ) continue;
		dfs(i);
		cnt++;
	} 
	cout<<cnt<<'\n';
	return 0;
}
