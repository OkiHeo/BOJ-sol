#include <iostream>
#include <stdio.h>
#include <math.h>
int main(){
	int T;
	scanf("%d", &T);
	
	while(T--){
		long long x, y;
		scanf("%d %d", &x, &y);
		
		long long distance = y-x;
		long long cnt;		// 이동횟수
		long long max=1;
		// 최고 이동 거리인 max를 구함 
		while(max*max<=distance){
			max++;
		}
        max--;
		// 남은 거리 remain 구함 
		long long remain = distance - max*max;
		cnt = 2*max-1+ceil((double)remain/max);
		printf("%d\n", cnt);
	}
	return 0;
}
