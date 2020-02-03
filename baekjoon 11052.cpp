#include <iostream>
using namespace std;

int n;
int cards[1001];
int dp[1001];		// dp[i] : i�� ī�� ������ �� �ִ� �ִ� ���� �ݾ� 

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>cards[i];
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i] = max(dp[i], dp[i-j]+cards[j]);
		}
	}
	
	cout<<dp[n]<<'\n';
	return 0;
}
