#include <iostream>
using namespace std;

int n;
int cards[1001];
int dp[1001];		// dp[i] : i개 카드 구매할 수 있는 최대 지불 금액 

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
