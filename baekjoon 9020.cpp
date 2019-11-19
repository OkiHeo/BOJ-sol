#include <iostream>
#include <stdio.h>
using namespace std;
bool primeArr[10001];
// � ���� �Ҽ����� �ƴ��� ǥ���� �� �迭(1: �Ҽ�) 
int primeNums[10001];
// �ε��� 0���� �Ҽ����� ������������ ����ִ�.

void findPrime(){
	// �����佺�׳׽��� ü �˰��� �̿�
	// n�� �ִ�� ������ 10,000������ ���� ���� �Ҽ� ���ϱ� 
	fill_n(primeArr, 10001, 1);
	primeArr[0]=0;
	primeArr[1]=0;
	for(int i=2; i*i<10001; i++){
		if(primeArr[i]==0){
			continue;
		}
		for(int j=i+i; j<10001; j+=i){
			primeArr[j]=0;
		}
	}
} 

int checkPrime(){
	// 2�̻��� �Ҽ����� �ε��� 0~cnt-1���� ������������ �����Ѵ�. 
	fill_n(primeNums, 10001, 0);
	int cnt=0;
	for(int i=2; i<10001; i++){
		if(primeArr[i]==1){
			primeNums[cnt++] = i;
		}
	}
	return cnt;
}
int main()
{
	int T, n;
	scanf("%d", &T);
	
	findPrime();
	int cnt = checkPrime();
	
	while(T--){
		scanf("%d", &n);
		if( n%2 != 0) return 0;			// �Է¹��� n�� ¦���� �ƴϸ� ����. 
		int minus=10000, mini=0, minj=0;
		for(int i=0; i<cnt; i++){
			int x = n-primeNums[i];
			// x�� ������ primeNums[i]���� ���ų� Ŀ���Ѵ�.(10�� 5+5 ���̽��� ���.) 
			if(primeArr[x]== 1 && x>=primeNums[i]){
				// �� �Ҽ��� ���� ���� ���� ���̽��� ����ؾ��Ѵ�. 
				if( minus > x-primeNums[i]){
					minus = x-primeNums[i];
					mini=primeNums[i];
					minj=x;						
				}
			}
		}
		printf("%d %d\n", mini, minj);
	}
	return 0;
 } 
