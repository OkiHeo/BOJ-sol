#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// 행렬의 사이즈 
int n;
// 1<= b <= 100,000,000,000 
long long int b;

// 단위행렬
vector<vector<int> > one(5, vector<int>(5)); 

vector<vector<int> > matmul(vector<vector<int> > a, vector<vector<int> > b){
	int size = a.size();
	
	vector<vector<int> > result(size, vector<int>(size));
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				result[i][j]+=(a[i][k]*b[k][j])%1000;
			}
			result[i][j]%=1000;
		}
	}
	return result;
}

vector<vector<int> > matpow(vector<vector<int> > a, long long int b){
	if( b==0 ){
		return one;
	}
	else if( b==1 ){
		return a;
	}
	else if( b%2==0 ){
		vector<vector<int> > tmp = matpow(a, b/2);
		return matmul(tmp, tmp);
	}
	else{
		vector<vector<int> > tmp = matpow(a, b-1);
		return matmul(a, tmp);
	}
}

void printmat(vector<vector<int> > v){
	int size = v.size();
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%d ", v[i][j]%1000);
		}
		printf("\n");
	}
}

int main(){
	scanf("%d %lld", &n, &b);
	// n*n사이즈 행렬 입력 
	vector<vector<int> > mat(n, vector<int>(n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
		one[i][i]=1;
	}
	
	vector<vector<int> > answer(n, vector<int>(n));
	answer = matpow(mat, b);
	
	printmat(answer);
	return 0; 
} 
