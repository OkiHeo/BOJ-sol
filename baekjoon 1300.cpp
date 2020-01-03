#include <iostream>
using namespace std;

long long int n, k;

int main(){
	cin>>n>>k;
	
	long long int small = 1;
	long long int big = n*n;
	long long int x;
	long long int answer;
	
	while( small<=big ){
		x = (small+big)/2;
		long long int numunderX=0;		// x���� ���� ���� 
		
		for(int i=1; i<=n; i++){
			numunderX+=min(x/i, n);
		}
		
		if( numunderX>=k ){
		// x���� ���� ������ k������ �����Ƿ� x�� �ٿ����Ѵ�.
			big = x-1;
			answer = x;		// ���� x�� ����,
							// ���� ���� numunderX�� ������ �������� ���ϸ�
							// answer�� ���ŵ��� �ʴ´�. 
		}
		else{
		// numunderX<k �� ��
		// x�� ũ�� �ؾ� �Ѵ�. 
			small = x+1;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
