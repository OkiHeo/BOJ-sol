#include <iostream>
using namespace std;

int tc;

int main(){
	int a, b;
	while(true){
		cin>>a>>b;
		if( a==0 && b==0 ) return 0;
		if( a<b && b%a==0){
			cout<<"factor\n";
			continue;
		}
		else if( a>b && a%b==0 ){
			cout<<"multiple\n";
			continue;
		}
		cout<<"neither\n";
	}
	return 0;
}
