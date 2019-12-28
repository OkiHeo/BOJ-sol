#include <iostream>
using namespace std;

int n;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int space = n-i; space>0; space--){
			cout<<' ';
		}
		for(int j=1; j<=i; j++){
			cout<<"* ";
		}
		cout<<'\n';
	}
	return 0;
}
