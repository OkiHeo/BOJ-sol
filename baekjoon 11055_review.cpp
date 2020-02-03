#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;
int dp[1000];

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		num.push_back(x);
	}
	
	dp[0] = num[0];
	
	int result= num[0];
	for(int i=1; i<n; i++){
		dp[i] = i;
		for(int j=0; j<=i; j++){
			if( num[i]>num[j] && dp[i] < dp[j]+num[i] ){
				dp[i] = dp[j]+num[i];
			}
		}
		result = max(result, dp[i]);
	}
	
	cout<<result<<'\n';
	return 0;
}
