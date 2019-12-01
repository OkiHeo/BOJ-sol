#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
int **tri;
int **triSum;

int main(){
	// 정수 삼각형의 크기 입력 
	scanf("%d", &n);
	// 정수 삼각형 할당 인덱스 1에서부터 사용. i 층에는 i개만큼 배열 할당 
	tri = new int*[n+1];
	for(int i=1; i<=n+1; i++){
		tri[i] = new int[i];
	}
	// 정수 삼각형의 합을 저장할 이차원 배열 할당.
	// triSum[i][j]에는 i층 j번째 원소까지의 합 중 가장 합이 큰 경로의 합 저장 
	triSum = new int*[n+1];
	for(int i=1; i<=n+1; i++){
		triSum[i] = new int[i];
	}
	
	// 정수 삼각형 입력
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &tri[i][j]);
		}
	}
	
	// 첫 번째 합 = 첫 번째 원소 
	triSum[1][1] = tri[1][1];
	// 두 번째 층부터 시작 
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			// 해당 층의 첫 원소일 때  
			if( j==1 ){
				triSum[i][j] = triSum[i-1][j]+tri[i][j];
			}
			// 해당 층의 마지막 원소일 때 
			else if( i==j ){
				triSum[i][j] = triSum[i-1][j-1]+tri[i][j];
			}
			// 안쪽에 있는 원소라면 이전 층의 j-1, j번째까지의 triSum 중에서
			// 큰 쪽을 선택하여 이번 층의 원소를 더한다. 
			else{
				triSum[i][j] = max(triSum[i-1][j-1], triSum[i-1][j])+tri[i][j];
			}
		}
	}
	int result=0;
	for(int i=1; i<=n; i++){
		result = max(result, triSum[n][i]);
	}
	printf("%d", result);
	return 0;
} 
