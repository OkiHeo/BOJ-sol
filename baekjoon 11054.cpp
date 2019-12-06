#include <iostream>
#include <cstdio>
using namespace std;

int N;
int A[1001];	// 인덱스 1~1000 사용
int up[1001], down[1001];

int solve(){
	// up, down 배열을 1로 초기화한다. 
	fill_n(up, 1001, 1);
	fill_n(down, 1001, 1);
	
	// A[i]까지 증가하는 부분수열 구한다. 
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			if( A[j] < A[i] ){
				up[i] = max(up[i], up[j]+1);
			}
		}
	}
	
	// 뒤에서부터 A[i]까지 증가하는 부분수열 구한다.
	//  == A[i]에서 끝까지 감소하는 부분수열 구한다. 
	for(int i=N; i>=1; i--){
		for(int k=N; k>=i; k--){
			if( A[i] > A[k] ){
				down[i] = max(down[i], down[k]+1);
			}
		}
	}
	int result=0;
	for(int i=1; i<=N; i++){
		result = max(result, up[i]+down[i]-1);
		// up[i]와 down[i]에 A[i]가 중복포함되므로 하나 제거해야한다 
	}
	return result;
}
int main(){
	// 입력 
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	
	// 출력 
	printf("%d\n",solve());
	return 0;
} 
