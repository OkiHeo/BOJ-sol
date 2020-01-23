#include <iostream>
using namespace std;

int n, M;
	// M : m*100    (dp 배열의 인덱스로 가격을 사용하기 위해.) 
int candy[5000][2];
			// [0] : 칼로리
			// [1] : 가격*100 
int dp[10001];
			// 0 ~ 10000을 사용한다. 

int main(){
	while(true){ 
		double m;
		cin>>n>>m;
		if( n==0 ) break;		// 0 0.00을 입력받으면 테스트케이스 입력을 끝마친다. 
		M = (int)(m*100+0.5);
		
		// n개의 사탕 정보 저장
		for(int i=0; i<n; i++){
			int c, P; double p;
			cin>>c>>p;
			P = (int)(p*100+0.5);
			candy[i][0] = c;
			candy[i][1] = P;
		}
		fill_n(dp, 10001, 0);
		
		// 돈 m을 가지고 구매할 수 있는 최대 칼로리를 구한다.
		for(int i=0; i<n; i++){
			int cal = candy[i][0];
			for(int ii= candy[i][1]; ii<=M; ii++){
				dp[ii] = max(dp[ii], dp[ii-candy[i][1]]+cal); 
			}
		}
		
		// 최대 칼로리를 찾아 출력한다.
		int result=0;
		for( int i=0; i<10001; i++ ){
			result = max(result, dp[i]);
		}
		cout<<result<<'\n';
	}
	return 0;
} 
