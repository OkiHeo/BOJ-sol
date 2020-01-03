#include <iostream>
using namespace std;

long long int n, k;

int main(){
	cin>>n>>k;
	
	long long int small = 1;
	long long int big = n*n;
	long long int x;
	long long int answer;
	
	while( small<=big ){
		x = (small+big)/2;
		long long int numunderX=0;		// x이하 수의 개수 
		
		for(int i=1; i<=n; i++){
			numunderX+=min(x/i, n);
		}
		
		if( numunderX>=k ){
		// x이하 수의 개수가 k개보다 많으므로 x를 줄여야한다.
			big = x-1;
			answer = x;		// 현재 x를 저장,
							// 만약 다음 numunderX가 조건을 만족하지 못하면
							// answer는 갱신되지 않는다. 
		}
		else{
		// numunderX<k 일 때
		// x를 크게 해야 한다. 
			small = x+1;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
