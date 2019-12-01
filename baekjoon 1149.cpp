#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int N;
int house[1001][3];
int tmp[3];		// ������� ������ �ּڰ��� ����. 
int choice[3];

int answer(){
	tmp[0] = house[1][0];	// ù��° ������ ���� ���� 
	tmp[1] = house[1][1];	// ù��° ������ �ʷ� ���� 
	tmp[2] = house[1][2];	// ù��° ������ �Ķ� ���� 
	
	// �ι�° ������ ������ ������ ��ȸ 
	for(int num=2; num<=N; num++){
		// �� ������ ���� ���� <- ���� ������ �ʷ�, �Ķ� ������ ��� �� ������ 
		choice[0] = house[num][0]+min(tmp[1], tmp[2]); 
		// �� ������ �ʷ� ���� <- ���� ������ ����, �Ķ� ������ ��� �� ������
		choice[1] = house[num][1]+min(tmp[0], tmp[2]);
		// �� ������ �Ķ� ���� <- ���� ������ ����, �ʷ� ������ ��� �� ������
		choice[2] = house[num][2]+min(tmp[0], tmp[1]);
		
		// �� ������� ������ �� �ֵ��� ����. 
		tmp[0] = choice[0];
		tmp[1] = choice[1];
		tmp[2] = choice[2];
	}
	
	// ��� ���� ��ȸ�� ��, ���� ������ ������ ����, �ʷ�, �Ķ� ������ ���� ��� �� �ּڰ� ���� 
	return min(min(tmp[0], tmp[1]), tmp[2]);
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		// �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ��� 
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}
	printf("%d\n", answer());
	return 0;
}
