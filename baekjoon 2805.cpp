#include <iostream>
using namespace std;

int n, m;
// n은 나무의 수. m은 필요한 나무 길이 
int tree[1000000];		// 인덱스 0~1,000,000사용 
int highest=0;			// 가장 높은 높이의 나무 저장 

void findmax(){
	int low = 0;
	int high = highest;
	long long int mid;
	long long int result;
	while( low<=high ){
		mid = (low+high)/2;
		long long int sum=0;
		
		// 자르는 길이에서 자르면 잘라지는 부분 sum에 저장 
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
