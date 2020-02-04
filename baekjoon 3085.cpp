#include <iostream>
using namespace std;

int n;
char candy[50][50];
int maxCandy=0;

void swap(char &a, char &b){
	char tmp = a;
	a = b;
	b = tmp;
}

void seq(){
	// candy[][] 전체에서 최대 연속부분의 원소 개수를 maxCandy에 저장한다.
	
	// 가로 연속부분 탐색
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int cnt=1;
			for(int k=j+1; k<n; k++){
				if( candy[i][j]==candy[i][k] ){
					cnt++;
				}
				else{
					maxCandy = max(maxCandy, cnt);
					break;
				}
				if( k==n-1 ) maxCandy = max(maxCandy, cnt);
				// 행의 끝까지 연속되면 else로 진입하지 않기때문에 필요한 부분. 
			}
		}
	} 
	
	// 세로 연속부분 탐색
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			int cnt=1;
			for(int k=i+1; k<n; k++){
				if(candy[i][j]==candy[k][j]){
					cnt++;
				}
				else{
					maxCandy = max(maxCandy, cnt);
					break;
				}
				if( k==n-1 ) maxCandy = max(maxCandy, cnt);
				// 열의 끝까지 연속되면 else로 진입하지 않기때문에 필요한 부분.
			}
		}
	} 
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>candy[i][j];
		}
	}
	
	// 가로로 연결된 두 개를 교환하는 경우
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			swap(candy[i][j], candy[i][j+1]);
			// 최대 연속 부분 탐색. 최대 연속부분 개수를 maxCandy에 저장 
			seq();
			swap(candy[i][j], candy[i][j+1]);
		}
	}
	// 세로로 연결된 두 개를 교환하는 경우 
	for(int j=0; j<n; j++){
		for(int i=0; i<n-1; i++){
			swap(candy[i][j], candy[i+1][j]);
			// 최대 연속 부분 탐색. 최대 연속부분 개수를 maxCandy에 저장
			seq();
			swap(candy[i][j], candy[i+1][j]);
		}
	}
	cout<<maxCandy<<'\n';
	return 0;
}
