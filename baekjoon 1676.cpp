#include <iostream>
using namespace std;

int n;
int two, five=0;

int main(){
	cin>>n;
	
	// 2���� �����ؼ� n������ ���� 2�� 5�� �μ��� �� �� �����ϴ��� ���� 
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
	// 10�� 2�� 5�� ���� �� �� �����͸�ŭ ���� �� �ִ�. 
	int result = min(two, five);
	cout<<result<<'\n';
	return 0;
}
