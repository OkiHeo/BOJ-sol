#include <iostream>
#include <algorithm>
using namespace std;

void find(int *a, int start, int end, int value){
	int mid = (start+end)/2;
	
	// 범위 내에서 값을 찾을 수 없으면 start와 end가 역전됨 
	if( start > end ){
		cout<<"0\n";
		return;
	}
	// start <= end 
	else{
		// mid값보다 value가 크면 
		if( a[mid] < value ){
			find(a, mid+1, end, value);
		}
		// mid값보다 value가 작으면 
		else if( a[mid] > value ){
			find(a, start, mid-1, value);
		}
		// mid값과 value가 같으면 
		else{
			cout<<"1\n";
			return;
		}
	}
}

int main(){
	int n, m;
	cin>>n;
	int *a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	cin>>m;
	int *nums = new int[m];
	for(int i=0; i<m; i++)
		cin>>nums[i];
		
	sort(a, a+n);
	
	//이분탐색으로 nums[i]의 값이 배열 a에 존재하는지 찾는다.
	for(int i=0; i<m; i++){
		find(a, 0, n-1, nums[i]);
	}
	return 0;
}
