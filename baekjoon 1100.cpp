#include <iostream>
using namespace std;

char chess[8][8];

int main(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin>>chess[i][j];
		}
	}
	
	int cnt=0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if( (i+j)%2==0 && chess[i][j]=='F' ){
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
