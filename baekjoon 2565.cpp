#include <iostream>
#include <vector>
using namespace std;

int n;
int A[501];				// 인덱스 1~500을 사용. 
						// A[i]에는 연결되어있는 B전봇대의 위치번호가 저장 
int amax, bmax;
int d[501];				// A전봇대 시작~A[i]전깃줄까지 순차적으로 연결되어있는 전깃줄 수 

int solve(){
	// A[i]의 전깃줄을 포함하는, 위에서부터 순차적으로 연결된 전깃줄의 수
	for(int i=1; i<=amax; i++){
		if( A[i]==0 ) continue;	// i위치에 연결된 전깃줄 없으면 패스
		// A[i]이전에 연결된 전깃줄들 탐색.
		for(int j=1; j<=i; j++){
			// A[i]가 연결된 지점 이전으로 순차적으로 연결되어야 체크한다. 
			if( A[j]<A[i] ){
				// A[j]까지 순차적으로 연결된 전깃줄의 개수 + 1 (A[i]번째 전깃줄 추가) 
				d[i] = max(d[i], d[j]+1);
			}
		} 
	}
	int result=0;
	for(int i=1; i<=amax; i++){
		result = max(result, d[i]);
	}
	return n-result;
}

int main(){
	cin>>n;	//전깃줄의 개수 입력
	// 두 전봇대 사이의 전깃줄 n개 입력 
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		amax = max(amax, a);	// 전깃줄이 연결된 제일 큰 연결위치 저장
		A[a] = b;				// A전봇대의 a위치->B전봇대의 b위치 전깃줄 연결 
		d[a] = 1;
	}
	cout<<solve();	
}
