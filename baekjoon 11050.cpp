#include <iostream>
using namespace std;

int n, k;
int fac[11];
int factorial(int n){
	if(n==0) return 1;
	if(n==1) return 1;
	if(fac[n]!=0)return fac[n];
	return fac[n]=n*factorial(n-1);
}

int main(){
	cin>>n>>k;
	cout<<factorial(n)/factorial(k)/factorial(n-k);
	return 0;
}
