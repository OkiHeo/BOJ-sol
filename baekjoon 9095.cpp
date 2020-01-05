#include <iostream>
using namespace std;

int t, n;
int d[11];

int main(){
	cin>>t;
	while(t--){
		fill_n(d, 11, 0);
		d[1]=1;
		d[2]=2;
		d[3]=4;
		cin>>n;
		for(int i=4; i<=n; i++){
			d[i] = d[i-1]+d[i-2]+d[i-3];
		}
		cout<<d[n]<<'\n';
	}
	return 0;
}
