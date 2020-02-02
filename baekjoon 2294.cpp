#include <iostream>
using namespace std;

int n, k;
int coin[100];
int dp[100][10001];
int IMPOSSIBLE = 1000000000;

int f(int idx, int money){
	if( idx==n && money==0 ){
		// ��� ������ �� ����߰�, ������ �� ���� 0���̸� �ϼ��ߴٴ� ��! 
		return 0;
	}
	if( idx==n && money>0 ){
		// ��� ������ �� ����ߴµ�, ������ �� ���� �����ִٸ� �� ���� ���� �� ����.
		// -1�� ����ϰ� �����Ѵ�. 
		return IMPOSSIBLE;
	} 
	// �̹� ���� ���� ã�Ƽ� �������ش�. 
	if( dp[idx][money]!=-1 ) return dp[idx][money];
	
	int result = f(idx+1, money);
	if( money>=coin[idx] ){
		result = min(result, f(idx, money-coin[idx])+1);
	} 
	return dp[idx][money] = result;
}

int main(){
	cin>>n>>k;
	// dp�迭�� -1�� �ʱ�ȭ�Ѵ�. 
	for(int i=0; i<100; i++){
		for(int j=0; j<10001; j++){
			dp[i][j] = -1;
		}
	}
	for(int i=0; i<n; i++){
		cin>>coin[i];
	}
	
	int result = f(0, k);
	if( result!=IMPOSSIBLE ){
		cout<<result<<'\n';
	}else cout<<"-1\n";
	return 0;
}
