#include <iostream>
using namespace std;

int n, s, num[20], cnt=0;

void partsum(int idx, int sum){
	if( idx>=n ) return;
	int tmp = sum + num[idx];
	if( tmp == s ) cnt++;
	partsum(idx+1, sum);		// num[idx]�� �������� �ʴ� ��� 
	partsum(idx+1, tmp);		// num[idx]�� �����ϴ� ��� 
}

int main(){
	// input 
	cin>>n>>s;
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	
	// solve
	// 1. ���Ұ� 1�� ~ n���� �κ������� ���Ѵ�.
	// 2. �� �κ������� ������ ���� s�̸� cnt�� 1 ������Ų��.
	partsum(0, 0);
	
	// 3. cnt�� ����Ѵ�.
	cout<<cnt<<'\n';
	return 0;
}
