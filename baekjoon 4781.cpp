#include <iostream>
using namespace std;

int n, M;
	// M : m*100    (dp �迭�� �ε����� ������ ����ϱ� ����.) 
int candy[5000][2];
			// [0] : Į�θ�
			// [1] : ����*100 
int dp[10001];
			// 0 ~ 10000�� ����Ѵ�. 

int main(){
	while(true){ 
		double m;
		cin>>n>>m;
		if( n==0 ) break;		// 0 0.00�� �Է¹����� �׽�Ʈ���̽� �Է��� ����ģ��. 
		M = (int)(m*100+0.5);
		
		// n���� ���� ���� ����
		for(int i=0; i<n; i++){
			int c, P; double p;
			cin>>c>>p;
			P = (int)(p*100+0.5);
			candy[i][0] = c;
			candy[i][1] = P;
		}
		fill_n(dp, 10001, 0);
		
		// �� m�� ������ ������ �� �ִ� �ִ� Į�θ��� ���Ѵ�.
		for(int i=0; i<n; i++){
			int cal = candy[i][0];
			for(int ii= candy[i][1]; ii<=M; ii++){
				dp[ii] = max(dp[ii], dp[ii-candy[i][1]]+cal); 
			}
		}
		
		// �ִ� Į�θ��� ã�� ����Ѵ�.
		int result=0;
		for( int i=0; i<10001; i++ ){
			result = max(result, dp[i]);
		}
		cout<<result<<'\n';
	}
	return 0;
} 
