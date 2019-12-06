#include <iostream>
#include <cstdio>
using namespace std;

int N;
int A[1001];	// �ε��� 1~1000 ���
int up[1001], down[1001];

int solve(){
	// up, down �迭�� 1�� �ʱ�ȭ�Ѵ�. 
	fill_n(up, 1001, 1);
	fill_n(down, 1001, 1);
	
	// A[i]���� �����ϴ� �κм��� ���Ѵ�. 
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			if( A[j] < A[i] ){
				up[i] = max(up[i], up[j]+1);
			}
		}
	}
	
	// �ڿ������� A[i]���� �����ϴ� �κм��� ���Ѵ�.
	//  == A[i]���� ������ �����ϴ� �κм��� ���Ѵ�. 
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
		// up[i]�� down[i]�� A[i]�� �ߺ����ԵǹǷ� �ϳ� �����ؾ��Ѵ� 
	}
	return result;
}
int main(){
	// �Է� 
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}
	
	// ��� 
	printf("%d\n",solve());
	return 0;
} 
