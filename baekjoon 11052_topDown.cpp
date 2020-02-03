#include <iostream>
using namespace std;

int n;
int cards[1001];
int dp[1001];

int buy(int n){
	if( n==0 ){
		return 0;
	}
	if( dp[n]!=0 ){
		return dp[n];
	}
	
	for(int i=1; i<=n; i++){
		dp[n] = max(dp[n], buy(n-i)+cards[i]);
	}
	return dp[n];
	
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>cards[i];
	}
	
	cout<<buy(n)<<'\n';
	return 0;
}
