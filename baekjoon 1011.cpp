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
		long long cnt;		// �̵�Ƚ��
		long long max=1;
		// �ְ� �̵� �Ÿ��� max�� ���� 
		while(max*max<=distance){
			max++;
		}
        max--;
		// ���� �Ÿ� remain ���� 
		long long remain = distance - max*max;
		cnt = 2*max-1+ceil((double)remain/max);
		printf("%d\n", cnt);
	}
	return 0;
}
