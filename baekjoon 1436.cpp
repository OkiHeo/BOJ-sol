#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);		// �� ��° ��ȭ�� ������ �ñ����� 
	
	int cnt=1, number=666;	// 666�� ���� ���� �����Ǽ�  
	int a, b, c;	// ���ӵ� �� �ڸ��� �ڸ����� ������ ���� 
	while(1){
		if( cnt == N ) break;
		number++;
		int numcopy = number;
		int serial = 0;
		while( numcopy ){
			int temp = numcopy%10;	// ���� �ڸ������� ���ʷ� �� 
			if( temp == 6 ){
				serial++;
			}
			else if( serial<3 ){	// �� ���� ���� 6�� �ƴϸ� serial �ʱ�ȭ 
				serial = 0;			// 6�� �������� �ȳ������Ƿ�! 
			}
			numcopy/=10;			// �� ���� �ڸ����� ���� �ڸ����� ������ 
		}							// ���� number�� ��� �ڸ��� �� �Ϸ� 
		if( serial >= 3 ){			// 6�� �� �� �̻� �������� ���� 
			cnt++;
		} 
	}
	printf("%d\n", number);
	return 0;
}
