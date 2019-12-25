#include <iostream>
using namespace std;

int mod = 1000000007;

long long int power(long long int a, long long int b){
	//a�� b������ ������
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
	
	// n!�� modulo ���� ��� facn�� ���� 
	for(long long int i=1; i<=n; i++){
		facn = (facn*i)%mod;
	}
	
	// k!�� modulo ���� ��� other�� ���� 
	for(long long int i=1; i<=k; i++){
		other = (other*i)%mod;
	}
	// (n-k)!�� modulo ���� ��� other�� ���� ����. 
	for(long long int i=1; i<=n-k; i++){
		other = (other*i)%mod;
	}
	
	// n!*( k!(n-k)! )^mod-2�� modulo���� ��� ����. 
	return (facn*power(other, mod-2))%mod;
}

int main(){
	long long int n, k;
	cin>>n>>k;
	cout<<comb(n,k);
	return 0;
} 
