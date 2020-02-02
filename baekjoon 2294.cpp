#include <iostream>
using namespace std;

int n, k;
int coin[100];
int dp[100][10001];
int IMPOSSIBLE = 1000000000;

int f(int idx, int money){
	if( idx==n && money==0 ){
		// 모든 동전을 다 사용했고, 만들어야 할 돈이 0원이면 완성했다는 뜻! 
		return 0;
	}
	if( idx==n && money>0 ){
		// 모든 동전을 다 사용했는데, 만들어야 할 돈이 남아있다면 이 돈은 만들 수 없다.
		// -1을 출력하고 종료한다. 
		return IMPOSSIBLE;
	} 
	// 이미 계산된 값은 찾아서 리턴해준다. 
	if( dp[idx][money]!=-1 ) return dp[idx][money];
	
	int result = f(idx+1, money);
	if( money>=coin[idx] ){
		result = min(result, f(idx, money-coin[idx])+1);
	} 
	return dp[idx][money] = result;
}

int main(){
	cin>>n>>k;
	// dp배열을 -1로 초기화한다. 
	for(int i=0; i<100; i++){
		for(int j=0; j<10001; j++){
			dp[i][j] = -1;
		}
	}
	for(int i=0; i<n; i++){
		cin>>coin[i];
	}
	
	int result = f(0, k);
	if( result!=IMPOSSIBLE ){
		cout<<result<<'\n';
	}else cout<<"-1\n";
	return 0;
}
