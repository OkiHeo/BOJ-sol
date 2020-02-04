#include <iostream>
using namespace std;

int n;
char candy[50][50];
int maxCandy=0;

void swap(char &a, char &b){
	char tmp = a;
	a = b;
	b = tmp;
}

void seq(){
	// candy[][] ��ü���� �ִ� ���Ӻκ��� ���� ������ maxCandy�� �����Ѵ�.
	
	// ���� ���Ӻκ� Ž��
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int cnt=1;
			for(int k=j+1; k<n; k++){
				if( candy[i][j]==candy[i][k] ){
					cnt++;
				}
				else{
					maxCandy = max(maxCandy, cnt);
					break;
				}
				if( k==n-1 ) maxCandy = max(maxCandy, cnt);
				// ���� ������ ���ӵǸ� else�� �������� �ʱ⶧���� �ʿ��� �κ�. 
			}
		}
	} 
	
	// ���� ���Ӻκ� Ž��
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			int cnt=1;
			for(int k=i+1; k<n; k++){
				if(candy[i][j]==candy[k][j]){
					cnt++;
				}
				else{
					maxCandy = max(maxCandy, cnt);
					break;
				}
				if( k==n-1 ) maxCandy = max(maxCandy, cnt);
				// ���� ������ ���ӵǸ� else�� �������� �ʱ⶧���� �ʿ��� �κ�.
			}
		}
	} 
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>candy[i][j];
		}
	}
	
	// ���η� ����� �� ���� ��ȯ�ϴ� ���
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			swap(candy[i][j], candy[i][j+1]);
			// �ִ� ���� �κ� Ž��. �ִ� ���Ӻκ� ������ maxCandy�� ���� 
			seq();
			swap(candy[i][j], candy[i][j+1]);
		}
	}
	// ���η� ����� �� ���� ��ȯ�ϴ� ��� 
	for(int j=0; j<n; j++){
		for(int i=0; i<n-1; i++){
			swap(candy[i][j], candy[i+1][j]);
			// �ִ� ���� �κ� Ž��. �ִ� ���Ӻκ� ������ maxCandy�� ����
			seq();
			swap(candy[i][j], candy[i+1][j]);
		}
	}
	cout<<maxCandy<<'\n';
	return 0;
}
