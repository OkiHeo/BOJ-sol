#include <iostream>
using namespace std;

int A[100][100];
int B[100][100];

int main(){
	int n, m, k;
	cin>>n>>m;
	// N*M 사이즈 행렬 A 입력 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>A[i][j];
		}
	}
	cin>>m>>k;
	// M*K 사이즈 행렬 B 입력 
	for(int i=0; i<m; i++){
		for(int j=0; j<k; j++){
			cin>>B[i][j];
		}
	}
	
	// 행렬곱셈의 결과는 N*K사이즈의 행렬. 
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			int c=0;
			for(int p=0; p<m; p++){
				c+=A[i][p]*B[p][j];
			}
			cout<<c<<' ';
		}
		cout<<"\n";
	}
	return 0;
}
