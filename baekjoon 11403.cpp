#include <iostream>
using namespace std;

int n;
bool graph[101][101];		// ����ġ ���� ���� �׷��� 

int main(){
	/* ������ ���� n�� �Է� */
	cin>>n;
	/* �׷����� ���� ��� �Է� */
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	
	/* n���� �ٿ� ���ļ� ������ ������ ������� �������� ���.
	���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1����, ������ 0����. */
	// floyd-washall �˰��� ����. 
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if( graph[i][k] && graph[k][j] ){
					graph[i][j] = true;
				}
			}
		}
	}
	
	// ��� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<graph[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
