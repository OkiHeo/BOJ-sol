#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		int tmp=i;
		int gen=tmp;
		while( tmp ){
			gen+=tmp%10;
			tmp/=10;
		}
		if( gen==n ){
			cout<<i<<'\n';
			return 0;
		}
	}
	
	// �����ڰ� �������� ������ 0�� ����ؾ��Ѵ�. 
	cout<<"0\n";
	return 0;
} 
