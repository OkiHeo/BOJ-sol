#include <iostream>
using namespace std;

int n, m;
int path[101][101];
int INF = 100000000;

void init(){
	// ��� ��θ� INF�� �ʱ�ȭ�Ѵ�. 
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			path[i][j] = INF;
			// �ڱ� �ڽ����� ���� �Ÿ��� 0
			if( i==j ) path[i][j] = 0;
		}
	}
}

void floyd(){
	// �÷��̵� �ͼ� �˰��� ���� 
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){		// i���� ��� 
			for(int j=1; j<=n; j++){	// j�� �����ϴµ�, k�� �����Ѵ�. 
				// �����Ÿ� �� ���Ѵ밡 �������� ������ 
				if( path[i][k]!=INF && path[k][j]!=INF ) 
					path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	init();
	// ���� �����, ������, �ɸ��� �ð� �Է�. 
	for(int i=0; i<m; i++){
		int s, e, d;
		cin>>s>>e>>d;
		// path �迭 ������Ʈ 
		// ����� ���� �� ���� ª�� ������ ������Ʈ���� 
		path[s][e] = min(path[s][e], d);
	}
	floyd();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(path[i][j]==INF || path[i][j]==0)
				cout<<0<<' ';
			else
				cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
