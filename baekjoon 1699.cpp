#include <iostream>
using namespace std;

int n;
int dp[100001];
	//[i] : j�� ����� ����� �� 

int main(){
	// n�Է�
	cin>>n;
	// dp�迭�� 1�θ� �̷���� �������� ��(maximum case)���� �ʱ�ȭ�Ѵ�. 
	for(int i=0; i<=n; i++){
		dp[i] = i;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j*j<=i; j++){
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	
	cout<<dp[n] <<'\n';
	return 0; 
}
