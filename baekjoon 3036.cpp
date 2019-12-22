#include <iostream>
using namespace std;

int n;
int r[100];

int gcd(int a, int b){
	return a%b?gcd(b, a%b):b;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>r[i];
	}
	for(int i=1; i<n; i++){
		int g = gcd(r[0], r[i]);
		cout<<r[0]/g<<'/'<<r[i]/g<<'\n';
	}
	return 0;
}
