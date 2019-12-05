#include <iostream>
using namespace std;

int N;
int A[1001];	// N최대값 1000이므로. 인덱스 1~1000 사용

// 수열 A의 i번째 수까지 증가하는 부분 수열의 원소 개수
int d[1001]; 

int solve(){
	int result=0;
	
	for(int i=1; i<=N; i++){
		// i번째 수 이전의 수들 중에서 A[i]보다 작은 수에 대해 조사. 
		for(int j=1; j<i; j++){
			if( A[i] > A[j] ){
				// i번째 수까지의 증가 수열의 길이
				// = i이전에 A[i]보다 작은 수까지의 증가 수열의 길이 + 1 (i를포함시킨다.) 
				d[i] = max( d[i], d[j]+1 );
			}
		}
		// d[i]를 갱신하면서, result에 가장 큰 d[i]를 갱신한다. 
		result = max(result, d[i]);
	}
	return result;	// 가장 긴 증가수열의 길이를 리턴. 
}

int main(){
	// 수열의 원소 개수 입력. 
	cin>>N;
	// N개의 원소 입력. 
	for(int i=1; i<=N; i++){
		cin>>A[i];
	}	
	fill_n(d, 1001, 1);
	cout<<solve()<<"\n";
	return 0;
} 
