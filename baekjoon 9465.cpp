#include <iostream>
using namespace std;

int t, n;
int sticker[2][100000];
int dp[100000][3];
			//[0] : 이전 열에서 아무것도 떼지 않았음
			//[1] : 이전 열에서 상단 스티커를 뗐음
			//[2] : 이전 열에서 하단 스티커를 뗐음 

int cal(int col, int status){
	if( col==n )
		return 0;	// n+1열에는 뗄 스티커가 존재하지 않으므로 0을 리턴. 
	if( dp[col][status]!=-1)
		return dp[col][status];
	
	// 1. 아무것도 떼지 않고 다음 열으로 넘어가는 경우 
	int result = cal(col+1, 0);
	// 2. 이전 열의 하단 스티커를 떼지 않았을 경우 -> 상단 스티커도 뗄 수 있다  
	if( status!=2 ){
		result = max(result, sticker[1][col]+cal(col+1, 2));
	}
	// 3. 이전 열의 상단 스티커를 떼지 않았을 경우 -> 하단 스티커도 뗄 수 있다 
	if( status!=1 ){
		result = max(result, sticker[0][col]+cal(col+1, 1));
	}
	return dp[col][status] = result; 
}

int main(){
	cin>>t;
	while(t--){
		// dp배열을 -1로 초기화한다. 
		for(int i=0; i<100000; i++){
			for(int j=0; j<3; j++){
				dp[i][j] = -1;
			}
		}
		cin>>n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin>>sticker[i][j];
			}
		}
		
		// 0열. 0열 이전 열에서 아무것도 떼지 않은 상태에서 시작한다. 
		cout<<cal(0, 0)<<'\n';
	}
	return 0;
}
