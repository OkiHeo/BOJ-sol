#include <iostream>
using namespace std;

int n;
int main(){
	cin>>n;
	int tmp = n;
	
	for(int i=2; i<=n; i++){
		while(tmp%i==0){
			tmp/=i;
			cout<<i<<'\n';
		}
	}
	return 0;
}
