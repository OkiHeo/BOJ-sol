#include <iostream>
#include <stdio.h>
using namespace std;
int T;	// �׽�Ʈ ���̽� ���� 
int H, W, N;	// �� ��, �� ��, �մ�no 
int roomNo;		// N��° �մ� �������� �� 

int main()
{
	// �׽�Ʈ���̽� ���� �Է� 
	scanf("%d", &T);
	while(T--){
		// �� ��, �� ��, �մ� ��ȣ �Է� 
		scanf("%d %d %d", &H, &W, &N);
		roomNo = 0;
		int height, width;
		/* 30 50 30�� ��� 3001ȣ�� �ƴ�
		102ȣ�� ���� ������ �ذ��ϱ� ����*/
		if( N%H == 0 ){
			height = H;
			width = N/H;
		}
		else{
			height = N%H;
			width = N/H+1;
		}
		roomNo += height*100+width;
		
		// N��° �մԿ��� ������ �� ��ȣ ���
		cout<<roomNo<<'\n';
	}
	return 0;
}
