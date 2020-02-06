#include <iostream>
using namespace std;

int n, s, num[20], cnt=0;

void partsum(int idx, int sum){
	if( idx>=n ) return;
	int tmp = sum + num[idx];
	if( tmp == s ) cnt++;
	partsum(idx+1, sum);		// num[idx]를 포함하지 않는 경우 
	partsum(idx+1, tmp);		// num[idx]를 포함하는 경우 
}

int main(){
	// input 
	cin>>n>>s;
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	
	// solve
	// 1. 원소가 1개 ~ n개인 부분집합을 구한다.
	// 2. 그 부분집합의 원소의 합이 s이면 cnt를 1 증가시킨다.
	partsum(0, 0);
	
	// 3. cnt를 출력한다.
	cout<<cnt<<'\n';
	return 0;
}
