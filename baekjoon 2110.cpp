#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int house[200001]; 
int mingap = 987654321;

void install(){ 
	int low = 0;
	int high = house[n]-house[1];
	int cnt=1;
	long long int gap;
	long long int maxgap=0;
	
	while( low<=high ){
		gap = (low+high)/2;
		int prev=1;		// ������ ������ ��ġ�� �� �ε��� 
		// 1�� ������ ������ ������ ��ġ.
		// ������ 2��°, ... c��°�� �����⸦ ��ġ�Ѵ�. 
		for(int i=2; i<=c; i++){
			for(int j=prev+1; j<=n; j++){
				if( house[prev]+gap <= house[j] ){
					cnt++;
					prev = j;
					break;
				}
			}
		}
		
		if( cnt >= c ){
			// gap�� ���� �� �÷����� �ǰڴ�! 
			low = gap+1;
			cnt=1;
			maxgap = gap;		// ������ gap�� ����. 
		}
		else{
			high = gap-1;
			cnt=1;
		}
	}
	cout<<maxgap<<'\n';
	return;
}

int main(){
	cin>>n>>c;
	for(int i=1; i<=n; i++){
		cin>>house[i];
	}
	// �Է¹��� ���� ��ġ �������� ����. 
	sort(house, house+n+1);
	
	// 1��°������ �����Ⱑ �ݵ�� ��ġ�Ǿ��
	// �� ������ ������ �Ÿ��� �ִ�� �� �� �ִ�.
	install();
	return 0; 
} 
