#include <iostream>
using namespace std;

int t, k;
int ch[501];		// 각 챕터별 파일 사이즈 저장. 인덱스 1~k사용 
int d[501][501]; 
int sum[501];
int INF = 987654321;
int main(){
	cin>>t;
	while(t--){
		cin>>k;
		
		for(int i=1; i<=k; i++){
			cin>>ch[i];
			sum[i] = sum[i-1]+ch[i];
		}
		
		for(int i=1; i<k; i++){			// i : 1 ~ k-1
			for(int a=1; a+i<=k; a++){
				int b = a+i;
				d[a][b] = INF;
				
				for(int mid = a; mid<b; mid++){		// mid : a ~ b-1까지 
					d[a][b] = min(d[a][b], d[a][mid]+d[mid+1][b]+sum[b]-sum[a-1]);
															// ch[a] + ch[a+1] + ... + ch[b]
				}
			}
		}
		cout<<d[1][k]<<'\n'; 
	}
	return 0;
}
