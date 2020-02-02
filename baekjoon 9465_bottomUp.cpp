#include <iostream>
using namespace std;

int t, n;
int sticker[2][100000];
int dp[100000][3];
			//[0] : 이전 열에서 아무것도 떼지 않았음
			//[1] : 이전 열에서 상단 스티커를 뗐음
			//[2] : 이전 열에서 하단 스티커를 뗐음 

int main(){
	cin>>t;
	while(t--){
		// dp배열을 0으로 초기화한다. 
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
			// 다음에 아무것도 안떼는 경우, xx, 1x, 2x의 경우 중 최댓값 선택 
			dp[i+1][0] = max(dp[i+1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
			// 다음에 상단 스티커를 떼는 경우, x1, 21의 경우 중 최댓값 선택 
			dp[i+1][1] = max(dp[i+1][1], max(dp[i][0], dp[i][2])+sticker[0][i]);
			// 다음에 하단 스티커를 떼는 경우, x2, 12의 경우 중 최댓값 선택
			dp[i+1][2] = max(dp[i+1][2], max(dp[i][0], dp[i][1])+sticker[1][i]); 
		}
		
		// n열까지 스티커를 뗀 경우 중 최댓값을 가지는 경우를 출력한다. 
		cout<<max(dp[n][0], max(dp[n][1], dp[n][2]))<<'\n';
	}
	return 0;
}
