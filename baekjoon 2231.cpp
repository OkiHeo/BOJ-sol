#include <cstdio>

// �������� ���ϴ� �Լ� decomp 
int decomp(int n){
	int t = 1;
	while( n >= t ){
		t*=10;
	}
	t/=10;
	int sum=0, temp = n;		// sum�� �� �ڸ����� ���� ����. 
	while( t!=0 ){
		sum+=temp/t;
		temp%=t;
		t/=10;
	}
	return sum+n;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=1; i<1000000; i++){	// i�� 1�������� Ű������ �����հ� N�� �� 
		int temp = decomp(i);		// i�� �������� temp�� ���� 
		if( temp == N ){			// i�� �������� N�� ���ٸ� i�� ������ 
			printf("%d\n", i);
			return 0; 				// ���� ���� ������ ��� �� ���α׷� ���� 
		}
	}
	printf("0\n");					// �����ڰ� �������������Ƿ� 0�� ��� 
	return 0;
}
