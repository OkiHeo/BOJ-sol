#include <iostream>
#include <stdio.h>
 
bool primeArr[123456*2+1];
int main()
{
	int n;
	while(1){
		scanf("%d", &n);
		if( n==0 ) break;
		// n���� ũ�� 2n���� �۰ų� ���� �Ҽ��� ������ ������.
		std::fill_n(primeArr, 123456*2+1, true);	// ������ �迭 true�� �ʱ�ȭ 
		primeArr[0]=false;
		primeArr[1]=false;
		for(int i=2; i*i<=2*n; i++){
			// i�� �Ҽ��� �ƴϸ� pass! 
			if( primeArr[i] == false ){
				continue;
			}
			// i�� �Ҽ��̹Ƿ� �ǳʶٰ� i�� ������� �Ҽ��� �ƴ��� ǥ�� 
			for(int j=i+i; j<=2*n; j+=i){
				primeArr[j] = false;
			}
		}
		
		// n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ���� ��� 
		int cnt=0;
		for(int k=n+1; k<=2*n; k++){
			if(primeArr[k]==true){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	// n�� 0�� �Էµ� ������ ��� �׽�Ʈ���̽��� �Է¹޴´�. 
	return 0;
} 
