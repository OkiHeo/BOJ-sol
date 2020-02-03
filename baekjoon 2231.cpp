#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		int tmp=i;
		int gen=tmp;
		while( tmp ){
			gen+=tmp%10;
			tmp/=10;
		}
		if( gen==n ){
			cout<<i<<'\n';
			return 0;
		}
	}
	
	// 생성자가 존재하지 않으면 0을 출력해야한다. 
	cout<<"0\n";
	return 0;
} 
