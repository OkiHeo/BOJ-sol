#include <iostream>
using namespace std;

int n;
int graph[100][100];
int path[100][100];
bool visit[100];

void search(int i){
	// ���� i�� ����� ������ �� �湮���� ���� ������ �湮. ( n level ) 
	for(int k=0; k<n; k++){
		if( graph[i][k] && !visit[k] ){
			visit[k] = true;		// �湮���� ���� ������ k�� �湮ó���ϰ� 
			search(k);				// k�� ����� �湮���� ���� ������ �湮. ( n+1 level ) 
		}
	}
}

int main(){
	// �Է� 
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	
	// ��� ã�� 
	for(int i=0; i<n; i++){
		fill_n(visit, 100, 0);		// �� ���� i�� Ž���� ������ visit�迭�� �ʱ�ȭ���־���Ѵ�. 
		search(i);
		
		// i�������� �湮�� �� �ִ� �������� visit�迭���� �˾Ƴ���, path�� �߰�. 
		for(int x=0; x<n; x++){
			if( visit[x] ){
				path[i][x] = 1;
			}
		}
	}
	
	// ã�� ��� ��� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<path[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
} 
