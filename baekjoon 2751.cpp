#include <iostream>
#include <stdio.h>
/* �������� ������ 100�������� �Ǵ� ��쿡�� ���������� �׻� O(nlogn)�� �����Ҽ� ����*/
void quickSort(int *data, int start, int end){
	int key, small, big, temp;
	if(start>=end){
		return;
	}
	key = start;
	big = start+1;
	small= end;
	
	while( big <= small ){
		while( data[big] <= data[key] ){
			big++;
		}
		while( data[small] >= data[key] && small>start){
			small--;
		}
		
		if( small < big ){
			temp = data[key];
			data[key] = data[small];
			data[small] = temp;
		}
		else{
			temp = data[small];
			data[small] = data[big];
			data[big] = temp;
		}
	}
	
	quickSort(data, start, small-1);
	quickSort(data, small+1, end);
}

int main()
{
	int N;
	int data[1000001];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &data[i]);
	}
	
	quickSort(data, 0, N-1);
	
	for(int i=0; i<N; i++){
		printf("%d\n", data[i]);
	}
	
	return 0;
}
