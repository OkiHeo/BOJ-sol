#include <iostream>
using namespace std;

int n, s, cnt=0;
int nums[20];

int main(){
	cin>>n>>s;
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}
	
	for(int bi=1; bi<(1<<n); bi++){
		int sum=0;
		// n이 5, bi가 10010이라면 우측에서부터 2번째, 5번째 인덱스 값을 포함한다는 뜻.
		// bi는 1 ~ 2^5 -1 이므로
		// bi의 개수는 원소가 5개인 집합의 부분집합 중 공집합을 제외한 개수가 된다. 
		for(int digit=0; digit<n; digit++){
			if( bi&(1<<digit) ){
				sum = sum+nums[digit];
			}
		}
		if( sum==s ) cnt++; 
	}
	
	cout<<cnt<<'\n';
	return 0;
}
