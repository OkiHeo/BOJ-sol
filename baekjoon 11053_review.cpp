/* 11053��
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ������ */

#include <cstdio>
#include <iostream>
using namespace std;

int N;                                    // �ִ� 1000
int serial[1001];                       // ������ i��° �� ����
int upSerial[1001];                   // i��° ������ �����ϴ� ���� ������ ��

void input(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &serial[i]);
	}
}

int solve(){
	int maxxx = 0;
	fill_n(upSerial, 1001, 1);      // upSerial�迭�� ��� 1�� �ʱ�ȭ�Ѵ�.
	for(int i=1; i<=N; i++){
		for(int j=1; j<i; j++){
			if( serial[j] < serial[i] )
			upSerial[i] = max(upSerial[i], upSerial[j]+1);
		}
		maxxx = max(maxxx, upSerial[i]);     // ���� ū upSerial���� maxxx�� ����.
	}
	return maxxx;
}

int main(){
	input();
	printf("%d\n", solve());        // ���� A�� �����ϴ� ���� �� �����ϴ� �κм��� ���� ���
	return 0;
}

