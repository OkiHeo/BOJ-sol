#include <iostream>
using namespace std;

int mod = 1000000007;

long long int power(long long int a, long long int b){
	//a의 b제곱을 구하자
	long long result = 1;
	while( b>0 ){
		if( b%2 ){
			result  = (result*a)%mod;
		}
		
		a = (a*a)%mod;
		b/=2;
	}
	return result;
}

long long int comb(long long int n, long long int k){
	long long int facn = 1;
	long long int other = 1;
	
	// n!의 modulo 연산 결과 facn에 저장 
	for(long long int i=1; i<=n; i++){
		facn = (facn*i)%mod;
	}
	
	// k!의 modulo 연산 결과 other에 저장 
	for(long long int i=1; i<=k; i++){
		other = (other*i)%mod;
	}
	// (n-k)!의 modulo 연산 결과 other에 누적 저장. 
	for(long long int i=1; i<=n-k; i++){
		other = (other*i)%mod;
	}
	
	// n!*( k!(n-k)! )^mod-2의 modulo연산 결과 리턴. 
	return (facn*power(other, mod-2))%mod;
}

int main(){
	long long int n, k;
	cin>>n>>k;
	cout<<comb(n,k);
	return 0;
} 
