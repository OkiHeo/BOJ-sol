#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int serial[2001];
bool result[2001][2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	// n���� ���� �Է� 
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>serial[i];
	}
	
	// �Էµ� ������ ���� �Ӹ���� �˻�
	for(int i=1; i<=n; i++){
		result[i][i] = true;
	}
		
	for(int i=1; i<n; i++){
		if( serial[i] == serial[i+1] ){
			result[i][i+1] = true;
		}
	}
	
	for(int i=2; i<n; i++){	// ���� 2~n-1����.(j=1�϶� 1, 2, 3�� Ž��...)  
		for(int j=1; j<=n-i; j++){			//(j=n-2�϶� n-2, n-1, n Ž��...) 
			// �� ��, �� �� ���� ����
			// �� ���̿� �����ϴ� ������ �Ӹ�����̸� ��ü�� true 
			if( serial[j]==serial[j+i] && result[j+1][j+i-1] ){
				result[j][j+i] = true;
			}
		}
	}
		 
	// m���� ���� �Է� 
	cin>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		// ����� ��� 
		if( result[a][b] == true ){
			cout<<"1\n";
		}	
		else{
			cout<<"0\n";
		}
	}
	return 0;
}
