#include <iostream>
using namespace std;

int n, m;
// n�� ������ ��. m�� �ʿ��� ���� ���� 
int tree[1000000];		// �ε��� 0~1,000,000��� 
int highest=0;			// ���� ���� ������ ���� ���� 

void findmax(){
	int low = 0;
	int high = highest;
	long long int mid;
	long long int result;
	while( low<=high ){
		mid = (low+high)/2;
		long long int sum=0;
		
		// �ڸ��� ���̿��� �ڸ��� �߶����� �κ� sum�� ���� 
		for(int i=0; i<n; i++){
			if( tree[i] > mid ){
				sum+=tree[i]-mid;
			}
		}
		 
		if( sum>=m ){
			low = mid+1;
			result = mid;
		}
		else if( sum<m ){
			high = mid-1;
		}
	}
	cout<<result<<'\n';
	return;
}
 
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>tree[i];
		highest = max(highest, tree[i]);
	}
	findmax();
	return 0;
}
