#include <iostream>
using namespace std;

int mod = 1000000000;
int N;
int memo[101][10]={ 0,};

int stair(int n){
	// 1자리수 계단수는 각각 1개이다. 
	for(int i=1; i<10; i++)
		memo[1][i] = 1;
	
	// i자리수, j로 끝나는 계단수
	// n자리수까지 계산한다.	
	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			// 이후에 0이 될 수 있는 경우는 이전에 1이었던 경우 뿐 
			if( j==0 ){
				memo[i][0] = memo[i-1][1]%mod;
			}
			// 이후에 9가 될 수 있는 경우는 이전에 8이었던 경우 뿐 
			else if( j==9 ){
				memo[i][j] = memo[i-1][8]%mod;
			}
			// 나머지 경우는 j의 이전, 이후 수 모두에 대해 가능하다. 
			else{
				memo[i][j] = (memo[i-1][j-1]+memo[i-1][j+1])%mod;
			}
		}
	}
	
	// n자리수의 계단수. 끝 숫자가 0~9인경우 모두의 합을 구한다. 
	int sum=0;
	for(int i=0; i<10; i++){
		sum = (sum+memo[n][i])%mod;
	}
	return sum;
}
int main(){
	cin>>N;
	cout<<stair(N);
	return 0;
} 
