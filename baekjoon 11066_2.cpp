#include <iostream>
using namespace std;

int t, k;
int dp[501][501];
int ch[501];
int sum[501];
int INF = 987654321;

int cal(int x, int y){
	if( dp[x][y] != INF ){
		// ch[x] ~ ch[y]���� ��ġ�� ��� �������ִٸ� return 
		return dp[x][y];
	}
	if( x==y ){
		// ch[x] ~ ch[x] ��ġ�� ����� 0 
		return dp[x][y] = 0;
	}
	if( x+1==y ){
		// ch[x] ~ ch[x+1] ��ġ�� ����� �� ������ ũ�� �� 
		return dp[x][y] = ch[x]+ch[x+1];
	}
	
	// ��� �κ��� �������� �� ������ �� �κ����� ������ ���� ������
	// ch[x]~ch[mid] + ch[mid+1]~ch[y] ��ġ�� ��� �ּڰ� ������Ʈ. 
	for(int mid=x; mid<y; mid++){
		int leftmin = cal(x, mid);
		int rightmin = cal(mid+1, y);
		dp[x][y] = min(dp[x][y], leftmin+rightmin);
	}
	return dp[x][y] += sum[y]-sum[x-1];
}

int main(){
	cin>>t;
	while(t--){
		cin>>k;
		for(int i=1; i<=k; i++){
			cin>>ch[i];
			sum[i] = sum[i-1]+ch[i];		// ~ch[i]������ ������ sum[i]�� ���� 
		}
		
		// dp[][]�� ��� INF�� �ʱ�ȭ. 
		for(int i=1; i<=k; i++){
			for(int j=1; j<=k; j++){
				dp[i][j] = INF;
			}
		}
		
		cout<<cal(1, k)<<'\n';
	}
	return 0;
}
