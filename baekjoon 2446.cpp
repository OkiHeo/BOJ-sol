#include <iostream>
using namespace std;

int n;
int main(){
	cin>>n;
	int i, j, k;
	for(i=1; i<=n; i++){
		for(j=1; j<i; j++) cout<<' ';
		for(k=2*n-2*i+1  ; k>=1; k--) cout<<'*';
		cout<<'\n';	
	}
	for(i=n-1; i>=1; i--){
		for(j=1; j<i; j++) cout<<' ';
		for(k=2*n-2*i+1  ; k>=1; k--) cout<<'*';
		cout<<'\n';	
	}
	return 0;
}
