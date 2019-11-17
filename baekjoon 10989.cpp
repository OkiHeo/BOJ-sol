#include <iostream>
#include <stdio.h>
using namespace std;
int N;
int cnt[10001];

int main()
{
	//수의 개수, 그 개수만큼의 수 입력 
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for( int i=0; i<10001; i++){
		for(int j=0; j<cnt[i]; j++){
			printf("%d\n", i);
		}
	}
	return 0;
}

//입출력을 cout, cin으로 했을때 시간초과오류 발생.
//printf와 scanf를 사용햐도록 하자. 
