#include <iostream>
using namespace std;

int main(){
	int n, m;
	int two=0, five=0;
	// 입력 
	cin>>n>>m;
	// N!
	for(long long i=2; i<=n; i*=2)
		two += n/i;
	for(long long i=5; i<=n; i*=5)
		five += n/i;

	// M!
	for(long long i=2; i<=m; i*=2)
		two -= m/i;
	for(long long i=5; i<=m; i*=5)
		five -= m/i;

	// (N-M)!
	for(long long i=2; i<=n-m; i*=2)
		two -= (n-m)/i;
	for(long long i=5; i<=n-m; i*=5)
		five -= (n-m)/i;
	
	// 결과 출력 
	int result=min(two, five);
	cout<<result<<'\n';
	return 0;
}
