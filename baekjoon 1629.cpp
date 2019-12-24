#include <iostream>
using namespace std;

int power(int a, int b, int c){
	// b�� 1�� �Ǹ� a%c�� �����Ѵ�. 
	if( b==1 ){
		return a%c;
	}
	
	// b�� 1�� �ƴ� ¦���̸� a�� b/2������ c�� ���� ������ ���� 
	if( b%2==0 ){
		long long int tmp=power(a, b/2, c)%c; 
		tmp *= tmp;
		tmp%=c;
		return tmp;
	}
	// b�� 1�� �ƴ� Ȧ���̸� a* a�� b-1������ c�� ���� ������ ���� 
	else{
		long long tmp = power(a, b-1, c)%c;
		tmp *= a;
		tmp%=c;
		return tmp;
	}
}

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	cout<<power(a, b, c);
	return 0;
}
