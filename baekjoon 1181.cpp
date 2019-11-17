#include <iostream>
#include <algorithm>

using namespace std;
string a[20000];
int n;

bool compare(string a, string b){
	if(a.length() < b.length() ){
		return 1;
	}
	else if(a.length() > b.length()){
		return 0;
	}
	// 길이가 같은 경우 
	else{
		return a<b;	// 사전 순으로 정렬 
	}
}
int main()
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	sort(a, a+n, compare);
	for(int i=0; i<n; i++){
		if( i+1<n && a[i] == a[i+1]){
			continue;
		}
		else{
			cout<<a[i]<<'\n';
		}
	}
	return 0;
}

