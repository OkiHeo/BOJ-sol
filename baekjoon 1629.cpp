#include <iostream>
using namespace std;

int power(int a, int b, int c){
	// b가 1이 되면 a%c를 리턴한다. 
	if( b==1 ){
		return a%c;
	}
	
	// b가 1이 아닌 짝수이면 a의 b/2제곱을 c로 나눈 나머지 리턴 
	if( b%2==0 ){
		long long int tmp=power(a, b/2, c)%c; 
		tmp *= tmp;
		tmp%=c;
		return tmp;
	}
	// b가 1이 아닌 홀수이면 a* a의 b-1제곱을 c로 나눈 나머지 리턴 
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
