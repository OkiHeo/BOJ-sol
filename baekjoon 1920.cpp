#include <iostream>
#include <algorithm>
using namespace std;

void find(int *a, int start, int end, int value){
	int mid = (start+end)/2;
	
	// ���� ������ ���� ã�� �� ������ start�� end�� ������ 
	if( start > end ){
		cout<<"0\n";
		return;
	}
	// start <= end 
	else{
		// mid������ value�� ũ�� 
		if( a[mid] < value ){
			find(a, mid+1, end, value);
		}
		// mid������ value�� ������ 
		else if( a[mid] > value ){
			find(a, start, mid-1, value);
		}
		// mid���� value�� ������ 
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
	
	//�̺�Ž������ nums[i]�� ���� �迭 a�� �����ϴ��� ã�´�.
	for(int i=0; i<m; i++){
		find(a, 0, n-1, nums[i]);
	}
	return 0;
}
