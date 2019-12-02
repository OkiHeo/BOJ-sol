#include <iostream>
using namespace std;

int cnt=0;
int memo[1000001];

int op(int n){
	int tmp=1;
	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;
	for(int i=4; i<=n; i++){
		memo[i] = memo[i-1]+1;
		if( i%2 == 0 ){
			memo[i] = min( memo[i/2]+1, memo[i] );
		}
		if( i%3 == 0 ){
			memo[i] = min( memo[i/3]+1, memo[i] );
		}
		// 1을 더해서, 2를 곱해서, 3을 곱해서 i가 되는 경우 중 연산 최솟값 
	}
	return memo[n];
}
int main(){
	int N;
	cin>>N;
	cout<<op(N);
	return 0;
}
