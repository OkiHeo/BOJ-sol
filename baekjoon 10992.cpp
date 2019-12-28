#include <iostream>
using namespace std;

int n;
int main(){
	cin>>n;
	
	for(int i=1; i<=n-1; i++){
		for(int j=n-i; j>0; j--){
			cout<<' ';
		}
		cout<<'*';
		if( i==1 ){
			cout<<'\n';
			continue;	
		}
		for(int k=1; k<=2*(i-1)-1; k++) cout<<' ';
		cout<<'*';
		cout<<'\n';
	}
	for(int i=1; i<=2*n-1; i++) cout<<'*';
	return 0;
}
