#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
long long int lan[10000];

int main(){
	cin>>n>>k;
	long long int high=0;
	for(int i=0; i<n; i++){
		cin>>lan[i];
		high = max(high, lan[i]);
	}
	sort(lan, lan+n);
	int low = 1;
	long long int maxlength=0;
	while( low<=high ){
		long long int mid = (low+high)/2;
		if( mid==0 ) break;
		
		int lannum=0;
		for(int i=0; i<n; i++){
			lannum += lan[i]/mid;
		}
		
		if( lannum>=k ){
			maxlength = max(maxlength, mid);
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	
	cout<<maxlength<<'\n';
	return 0;
}
