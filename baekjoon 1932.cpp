#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
int **tri;
int **triSum;

int main(){
	// ���� �ﰢ���� ũ�� �Է� 
	scanf("%d", &n);
	// ���� �ﰢ�� �Ҵ� �ε��� 1�������� ���. i ������ i����ŭ �迭 �Ҵ� 
	tri = new int*[n+1];
	for(int i=1; i<=n+1; i++){
		tri[i] = new int[i];
	}
	// ���� �ﰢ���� ���� ������ ������ �迭 �Ҵ�.
	// triSum[i][j]���� i�� j��° ���ұ����� �� �� ���� ���� ū ����� �� ���� 
	triSum = new int*[n+1];
	for(int i=1; i<=n+1; i++){
		triSum[i] = new int[i];
	}
	
	// ���� �ﰢ�� �Է�
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &tri[i][j]);
		}
	}
	
	// ù ��° �� = ù ��° ���� 
	triSum[1][1] = tri[1][1];
	// �� ��° ������ ���� 
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			// �ش� ���� ù ������ ��  
			if( j==1 ){
				triSum[i][j] = triSum[i-1][j]+tri[i][j];
			}
			// �ش� ���� ������ ������ �� 
			else if( i==j ){
				triSum[i][j] = triSum[i-1][j-1]+tri[i][j];
			}
			// ���ʿ� �ִ� ���Ҷ�� ���� ���� j-1, j��°������ triSum �߿���
			// ū ���� �����Ͽ� �̹� ���� ���Ҹ� ���Ѵ�. 
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
