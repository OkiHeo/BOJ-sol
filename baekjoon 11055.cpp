#include <iostream>
using namespace std;

int n;
int serial[1001];
int partsum[1001];
// 인덱스 1~min(1000, n)까지 사용. 

int main(){
	// 입력 및 초기화 
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>serial[i];
		
	partsum[1] = serial[1];
	int partsumMax=partsum[1];
	
	// 가장 긴 증가하는 부분수열의 합 구하기 
	for(int i=2; i<=n; i++){
		partsum[i] = serial[i];		// 본인만 포함하는 가장 작은 케이스에서 시작. 
		for(int j=1; j<=i; j++){
			if( serial[i]>serial[j] && partsum[j]+serial[i] > partsum[i]){
				partsum[i] = partsum[j] + serial[i];
			}
		}
		partsumMax = max(partsumMax, partsum[i]); 
	}
	cout<<partsumMax<<'\n';
	return 0;
}
