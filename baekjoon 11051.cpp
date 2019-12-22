#include <iostream>
using namespace std;

int n, k;
int comb[1001][1001];

int main(){
	cin>>n>>k;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=k; j++){
			if( i==k ){
				comb[i][j] = 1;
			}
			else if( j==0 ){
				comb[i][j] = 1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<=k; j++){
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%10007;
		}
	}
	cout<<comb[n][k];
	return 0;
}
