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
		// n�� 5, bi�� 10010�̶�� ������������ 2��°, 5��° �ε��� ���� �����Ѵٴ� ��.
		// bi�� 1 ~ 2^5 -1 �̹Ƿ�
		// bi�� ������ ���Ұ� 5���� ������ �κ����� �� �������� ������ ������ �ȴ�. 
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
