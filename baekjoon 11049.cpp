#include <iostream>
using namespace std;

int n;
int mat[501][2];
int INF = 987654321;
int dp[501][501];

int calMin(int s, int e){
	if( dp[s][e]!=INF )
		return dp[s][e];
	if( s==e )
		return dp[s][e]=0;
	if( s+1 == e )
		return dp[s][e] = mat[s][0]*mat[s][1]*mat[e][1];
	
	for(int mid=s; mid<e; mid++){
		int left = calMin(s, mid);
		int right = calMin(mid+1, e);
		dp[s][e] = min(dp[s][e], (left+right)+(mat[s][0]*mat[mid][1]*mat[e][1]));
	}
	return dp[s][e];
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>mat[i][0]>>mat[i][1];
	}
	// dp배열 INF로 초기화 
	for(int i=0; i<501; i++){
		for(int j=0; j<501; j++){
			dp[i][j] = INF;
		}
	}
	
	cout<<calMin(1, n)<<'\n';
	return 0;
}
