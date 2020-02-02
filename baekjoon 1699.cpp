#include <iostream>
using namespace std;

int n;
int dp[100001];
	//[i] : j를 만드는 방법의 수 

int main(){
	// n입력
	cin>>n;
	// dp배열을 1로만 이루어진 제곱수의 합(maximum case)으로 초기화한다. 
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
