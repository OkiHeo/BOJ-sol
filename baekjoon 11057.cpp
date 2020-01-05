#include <iostream>
using namespace std;

int n;
int cnt[1001][10];
// cnt[i][j]�� i�ڸ���. ���� �ڸ����� j�� ���������� ���� 
// ���̰� n�� ������ ���� ������ 10007�� ���� ������ ����.

int main(){
	cin>>n;
	for(int i=0; i<=9; i++){
		// ���ڸ��� �������� 
		cnt[1][i]=1;
	}
	
	for(int digit=2; digit<=n; digit++){
		for(int num=0; num<10; num++){
			for(int tmp=0; tmp<=num; tmp++){
				cnt[digit][num] = (cnt[digit][num]%10007+cnt[digit-1][tmp]%10007)%10007;
			}
		}
	}
	
	int cntsum=0;
	for(int i=0; i<10; i++)
		cntsum= (cntsum%10007+cnt[n][i]%10007)%10007;
	cout<<cntsum%10007<<'\n';
	return 0;
} 
