#include <iostream>
using namespace std;

int n;
int cnt[1001][10];
// cnt[i][j]는 i자릿수. 일의 자리수가 j인 오르막수의 개수 
// 길이가 n인 오르막 수의 개수를 10007로 나눈 나머지 저장.

int main(){
	cin>>n;
	for(int i=0; i<=9; i++){
		// 한자리수 오르막수 
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
