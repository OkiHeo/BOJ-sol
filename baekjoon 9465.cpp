#include <iostream>
using namespace std;

int t, n;
int sticker[2][100000];
int dp[100000][3];
			//[0] : ���� ������ �ƹ��͵� ���� �ʾ���
			//[1] : ���� ������ ��� ��ƼĿ�� ����
			//[2] : ���� ������ �ϴ� ��ƼĿ�� ���� 

int cal(int col, int status){
	if( col==n )
		return 0;	// n+1������ �� ��ƼĿ�� �������� �����Ƿ� 0�� ����. 
	if( dp[col][status]!=-1)
		return dp[col][status];
	
	// 1. �ƹ��͵� ���� �ʰ� ���� ������ �Ѿ�� ��� 
	int result = cal(col+1, 0);
	// 2. ���� ���� �ϴ� ��ƼĿ�� ���� �ʾ��� ��� -> ��� ��ƼĿ�� �� �� �ִ�  
	if( status!=2 ){
		result = max(result, sticker[1][col]+cal(col+1, 2));
	}
	// 3. ���� ���� ��� ��ƼĿ�� ���� �ʾ��� ��� -> �ϴ� ��ƼĿ�� �� �� �ִ� 
	if( status!=1 ){
		result = max(result, sticker[0][col]+cal(col+1, 1));
	}
	return dp[col][status] = result; 
}

int main(){
	cin>>t;
	while(t--){
		// dp�迭�� -1�� �ʱ�ȭ�Ѵ�. 
		for(int i=0; i<100000; i++){
			for(int j=0; j<3; j++){
				dp[i][j] = -1;
			}
		}
		cin>>n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin>>sticker[i][j];
			}
		}
		
		// 0��. 0�� ���� ������ �ƹ��͵� ���� ���� ���¿��� �����Ѵ�. 
		cout<<cal(0, 0)<<'\n';
	}
	return 0;
}
