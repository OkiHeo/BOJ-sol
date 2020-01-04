#include <iostream>
using namespace std;

int t, k;
int dp[501][501];
int ch[501];
int sum[501];
int INF = 987654321;

int cal(int x, int y){
	if( dp[x][y] != INF ){
		// ch[x] ~ ch[y]까지 합치는 비용 계산된적있다면 return 
		return dp[x][y];
	}
	if( x==y ){
		// ch[x] ~ ch[x] 합치는 비용은 0 
		return dp[x][y] = 0;
	}
	if( x+1==y ){
		// ch[x] ~ ch[x+1] 합치는 비용은 두 파일의 크기 합 
		return dp[x][y] = ch[x]+ch[x+1];
	}
	
	// 어느 부분을 기준으로 이 구간을 두 부분으로 나누는 것이 좋을까
	// ch[x]~ch[mid] + ch[mid+1]~ch[y] 합치는 비용 최솟값 업데이트. 
	for(int mid=x; mid<y; mid++){
		int leftmin = cal(x, mid);
		int rightmin = cal(mid+1, y);
		dp[x][y] = min(dp[x][y], leftmin+rightmin);
	}
	return dp[x][y] += sum[y]-sum[x-1];
}

int main(){
	cin>>t;
	while(t--){
		cin>>k;
		for(int i=1; i<=k; i++){
			cin>>ch[i];
			sum[i] = sum[i-1]+ch[i];		// ~ch[i]까지의 누적합 sum[i]에 저장 
		}
		
		// dp[][]를 모두 INF로 초기화. 
		for(int i=1; i<=k; i++){
			for(int j=1; j<=k; j++){
				dp[i][j] = INF;
			}
		}
		
		cout<<cal(1, k)<<'\n';
	}
	return 0;
}
