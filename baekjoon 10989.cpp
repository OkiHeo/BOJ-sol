#include <iostream>
#include <stdio.h>
using namespace std;
int N;
int cnt[10001];

int main()
{
	//���� ����, �� ������ŭ�� �� �Է� 
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

//������� cout, cin���� ������ �ð��ʰ����� �߻�.
//printf�� scanf�� ����ᵵ�� ����. 
