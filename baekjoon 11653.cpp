#include <iostream>
#include <algorithm>
using namespace std;

int n;
int prime[10000000];
int numprime=0;
int INF = 10000000;
int main(){
	cin>>n;
	int tmp = n;
	
	for(int i=2; i<=n; i++){
		prime[i] = i;
	}
	for(int i=2, j; i*i<=n; i++){
		if( prime[i]==i ){
			numprime++;
			for(int j=i+i; j<=n; j=j+i){
				prime[j]=INF;
			}
		}
	}
	sort(prime, prime+numprime);

	int i=2;
	while(tmp!=1){
		while(tmp%prime[i]==0){
			tmp/=prime[i];
			cout<<prime[i]<<'\n';
		}
		i++;
	}
	return 0;
}
