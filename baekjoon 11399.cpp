#include <iostream>
#include <algorithm>
using namespace std;

int n;
int time[1001]={0,};
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>time[i];
	}
	// �ð��� ���� �ɸ��� ��� ������� ���� ���� �Ѵ�. 
	sort(time, time+n+1);
	long long int sum=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			sum +=time[j];
		}
	}
	cout<<sum;
	return 0;
}
