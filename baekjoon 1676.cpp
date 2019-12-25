#include <iostream>
using namespace std;

int n;
int two, five=0;

int main(){
	cin>>n;
	
	// 2부터 시작해서 n까지의 수에 2와 5가 인수로 몇 개 존재하는지 센다 
	for(int i=2; i<=n; i++){
		int tmp=i;
		while( tmp%2==0 ){
			tmp = tmp/2;
			two++;
		}
		while( tmp%5==0 ){
			tmp = tmp/5;
			five++;
		}
	}
	
	// 2*5=10
	// 10은 2와 5의 개수 중 더 작은것만큼 만들 수 있다. 
	int result = min(two, five);
	cout<<result<<'\n';
	return 0;
}
