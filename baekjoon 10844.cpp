#include <iostream>
using namespace std;

int mod = 1000000000;
int N;
int memo[101][10]={ 0,};

int stair(int n){
	// 1�ڸ��� ��ܼ��� ���� 1���̴�. 
	for(int i=1; i<10; i++)
		memo[1][i] = 1;
	
	// i�ڸ���, j�� ������ ��ܼ�
	// n�ڸ������� ����Ѵ�.	
	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			// ���Ŀ� 0�� �� �� �ִ� ���� ������ 1�̾��� ��� �� 
			if( j==0 ){
				memo[i][0] = memo[i-1][1]%mod;
			}
			// ���Ŀ� 9�� �� �� �ִ� ���� ������ 8�̾��� ��� �� 
			else if( j==9 ){
				memo[i][j] = memo[i-1][8]%mod;
			}
			// ������ ���� j�� ����, ���� �� ��ο� ���� �����ϴ�. 
			else{
				memo[i][j] = (memo[i-1][j-1]+memo[i-1][j+1])%mod;
			}
		}
	}
	
	// n�ڸ����� ��ܼ�. �� ���ڰ� 0~9�ΰ�� ����� ���� ���Ѵ�. 
	int sum=0;
	for(int i=0; i<10; i++){
		sum = (sum+memo[n][i])%mod;
	}
	return sum;
}
int main(){
	cin>>N;
	cout<<stair(N);
	return 0;
} 
