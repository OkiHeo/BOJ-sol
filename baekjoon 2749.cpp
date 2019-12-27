#include <iostream>
#include <vector>
using namespace std;

long long int n;
int mod = 1000000;
vector<vector<long long int> > one(2, vector<long long int>(2));

vector<vector<long long int> > matmul(vector<vector<long long int> > a, vector<vector<long long int> > b){
	int size = a.size();
	vector<vector<long long int> > result(size, vector<long long int>(size));
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				result[i][j]+=(a[i][k]*b[k][j])%mod;
			}
			result[i][j]%=mod;
		}
	}
	return result;
}

vector<vector<long long int> > matpow(vector<vector<long long int> > a, long long int b){
	if( b==0 ){
		return one;
	}
	else if(b==1){
		return a;
	}
	else if(b%2==0){
		vector<vector<long long int> > tmp = matpow(a, b/2);
		return matmul(tmp, tmp);
	}
	else{
		vector<vector<long long int> > tmp = matpow(a, b-1);
		return matmul(a, tmp);
	}
}

int main(){
	cin>>n;
	one[0][0]=1; one[1][1]=1;
	
	vector<vector<long long int> > mat(2, vector<long long int>(2));
	mat[0][0]=mat[0][1]=mat[1][0]=1;
	mat[1][1]=0;
	
	vector<vector<long long int> > result(2, vector<long long int>(2));
	result = matpow(mat, n);
	
	cout<<result[0][1]%mod<<'\n';
	return 0;
}
