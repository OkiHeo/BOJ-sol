#include <iostream>
using namespace std;

int t, n;
int sticker[2][100000];
int dp[100000][3];
			//[0] : ���� ������ �ƹ��͵� ���� �ʾ���
			//[1] : ���� ������ ��� ��ƼĿ�� ����
			//[2] : ���� ������ �ϴ� ��ƼĿ�� ���� 

int main(){
	cin>>t;
	while(t--){
		// dp�迭�� 0���� �ʱ�ȭ�Ѵ�. 
		for(int i=0; i<100000; i++){
			for(int j=0; j<3; j++){
				dp[i][j] = 0;
			}
		}
		cin>>n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin>>sticker[i][j];
			}
		}
		
		for(int i=0; i<n; i++){
			// ������ �ƹ��͵� �ȶ��� ���, xx, 1x, 2x�� ��� �� �ִ� ���� 
			dp[i+1][0] = max(dp[i+1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
			// ������ ��� ��ƼĿ�� ���� ���, x1, 21�� ��� �� �ִ� ���� 
			dp[i+1][1] = max(dp[i+1][1], max(dp[i][0], dp[i][2])+sticker[0][i]);
			// ������ �ϴ� ��ƼĿ�� ���� ���, x2, 12�� ��� �� �ִ� ����
			dp[i+1][2] = max(dp[i+1][2], max(dp[i][0], dp[i][1])+sticker[1][i]); 
		}
		
		// n������ ��ƼĿ�� �� ��� �� �ִ��� ������ ��츦 ����Ѵ�. 
		cout<<max(dp[n][0], max(dp[n][1], dp[n][2]))<<'\n';
	}
	return 0;
}
