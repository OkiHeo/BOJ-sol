#include <iostream>
#include <stdio.h>

bool primeArr[1000001];
// 1~1000000�ε����� 1�̸� �Ҽ��̴�.
// 1,000,000������ ���� ũ�⶧����
// �����佺�׳׽��� ü�� �̿��غ����� ����. 

void prime(int m, int n){
	//primeArr�� ���� ��� 1���� �ʱ�ȭ�Ѵ�.
	std::fill_n(primeArr, 1000001, 1);
	// 1�� �Ҽ��� �ƴ��� ǥ���Ѵ�.
	primeArr[1] = 0;
	// 2���� n�� �����ٱ��� �ݺ��ϸ� �����佺�׳׽��� ü �˰��� ����
	for(int q=2; q*q<=n; q++){
		if(primeArr[q] == 0){
			continue;
		}
		for(int k=q+q; k<=n; k+=q){
			primeArr[k]=0;
		}
	}	
}

int main()
{
	int M, N;
	std::cin>>M>>N;
	
	prime(M, N);
	
	//M�� N������ �Ҽ�(primeArr[] == 1 ) ��� 
	for(int i=M; i<=N; i++){
		if(primeArr[i]==1){
			printf("%d\n", i);
		}
	} 
	return 0;
}
