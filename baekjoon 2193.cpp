#include <iostream>
using namespace std;

int n;
long long int pn[91][2];
// pn[i][0] : i�ڸ� ��ģ��. 0���� �����°� ����
// pn[i][1] : i�ڸ� ��ģ��. 1���� �����°� ����

int main(){
	cin>>n;
	pn[1][0] = 0;
	pn[1][1] = 1;
	
	for(int i=2; i<=n; i++){
		pn[i][0] = pn[i-1][0] + pn[i-1][1];
		pn[i][1] = pn[i-1][0];
	}
	cout<<pn[n][0]+pn[n][1]<<'\n';
	return 0;
} 
