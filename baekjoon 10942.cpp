#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int serial[2001];
bool result[2001][2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	// n개의 수열 입력 
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>serial[i];
	}
	
	// 입력된 수열에 대해 팰린드롬 검사
	for(int i=1; i<=n; i++){
		result[i][i] = true;
	}
		
	for(int i=1; i<n; i++){
		if( serial[i] == serial[i+1] ){
			result[i][i+1] = true;
		}
	}
	
	for(int i=2; i<n; i++){	// 길이 2~n-1까지.(j=1일때 1, 2, 3을 탐색...)  
		for(int j=1; j<=n-i; j++){			//(j=n-2일때 n-2, n-1, n 탐색...) 
			// 맨 앞, 맨 뒤 원소 같고
			// 그 사이에 존재하는 수열이 팰린드롬이면 전체는 true 
			if( serial[j]==serial[j+i] && result[j+1][j+i-1] ){
				result[j][j+i] = true;
			}
		}
	}
		 
	// m개의 질문 입력 
	cin>>m;
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		// 결과를 출력 
		if( result[a][b] == true ){
			cout<<"1\n";
		}	
		else{
			cout<<"0\n";
		}
	}
	return 0;
}
