/*
n���� ������ �̷���� ������ ������ �־�����. �츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. ��, ���� �� �� �̻� �����ؾ� �Ѵ�.

���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. ���⼭ ������ 12+21�� 33�� ������ �ȴ�.

�Է�

ù° �ٿ� ���� n(1 �� n �� 100,000)�� �־����� ��° �ٿ��� n���� ������ �̷���� ������ �־�����. ���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���

ù° �ٿ� ���� ����Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
int n;
int sum[MAX];
int serial[MAX];

void input(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>serial[i];
	}
}

int solve(){
	// ù ��° ���ҷ� ���� ū ������, ù ��° ������ �ʱ�ȭ. 
	int sumMax=serial[0];
	sum[0] = serial[0];
	for(int i=1; i<n; i++){
		// '���� ���� < ���� ������ + �������' �� �� �� ū ���� sum[i]�� ����. 
		sum[i] = max(sum[i-1]+serial[i], serial[i]);
		// ���� ū �������� �����Ѵ�. 
		sumMax = max(sumMax, sum[i]);
	}
	return sumMax;
}

int main(){
	input();
	cout<<solve();
	return 0;
}