#include <iostream>
#include <algorithm>
using namespace std;

int N;
string serial[1000];

bool compare(string a, string b){
	if( a.length() != b.length()){
		return a.length()<b.length();
	}
	else{	// 길이가 같은 경우 
		int suma=0, sumb=0;
		for(int i=0; i<a.length(); i++){
			if(a[i]-'0' >= 0 && a[i]-'0'<=9){
				suma+=a[i]-'0';
			}
		}
		for(int i=0; i<b.length(); i++){
			if(b[i]-'0' >= 0 && b[i]-'0'<=9){
				sumb+=b[i]-'0';
			}
		}
		if( suma!=sumb){
			return suma<sumb;
		}
		else{
			return a<b;
		} 
	}
}
int main()
{
	cin>>N;
	for(int k=0; k<N; k++){
		cin>>serial[k];
	}
	sort(serial, serial+N, compare);
	for(int k=0; k<N; k++){
		cout<<serial[k]<<'\n';
	}
	return 0;
}
