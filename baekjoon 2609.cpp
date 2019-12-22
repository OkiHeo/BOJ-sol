#include <iostream>
using namespace std;

int a, b;

int main(){
	cin>>a>>b;
	int aa=a, bb=b;
	int mok, nmg;
	while( bb!=0 ){
		mok = aa/bb;
		nmg = aa%bb;
		aa=bb;
		bb=nmg;
	}
	cout<<aa<<'\n'<<a*b/aa<<'\n';
	return 0;	
}
