#include <iostream>
#include <stdio.h>
using namespace std;
bool primeArr[10001];
// 어떤 수가 소수인지 아닌지 표시해 둔 배열(1: 소수) 
int primeNums[10001];
// 인덱스 0부터 소수들이 오름차순으로 들어있다.

void findPrime(){
	// 에라토스테네스의 체 알고리즘 이용
	// n이 최대로 가능한 10,000까지의 수에 대해 소수 구하기 
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
	// 2이상의 소수들을 인덱스 0~cnt-1까지 오름차순으로 저장한다. 
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
		if( n%2 != 0) return 0;			// 입력받은 n이 짝수가 아니면 종료. 
		int minus=10000, mini=0, minj=0;
		for(int i=0; i<cnt; i++){
			int x = n-primeNums[i];
			// x는 언제나 primeNums[i]보다 같거나 커야한다.(10은 5+5 케이스를 고려.) 
			if(primeArr[x]== 1 && x>=primeNums[i]){
				// 두 소수의 차가 가장 작은 케이스를 출력해야한다. 
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
