#include <iostream>
#include <stdio.h>

bool prime(int n){
	if( n<2 )
		return false;
	for(int i=2; i*i<=n; i++){
		if( n%i == 0 )
			return false;
	}
	return true;
}

int main()
{
	int N, cnt=0;
	// ���� ���� �Է� 
	scanf("%d", &N);
	// N����ŭ�� �� �Է� 
	int *arr = new int[N];
	for(int i=0; i<N; i++){
		std::cin>>arr[i];
	}
	
	// �Ҽ� �Ǻ��ϱ�
	for(int i=0; i<N; i++){
		if(prime(arr[i]))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
} 
