#include <iostream>
using namespace std;

int N;
int count;
bool *arr;
bool *dup;
bool *ddown;

void findQueen(int n){
	if( n>=N ) count++;
	  
	for(int i=0; i<N; i++){		// (n, x)에 퀸을 배치할수있는지 체크
		if( arr[i]==true ) continue;
		if( dup[n+i] == true || ddown[N-1+n-i]==true ) continue;
		arr[i] = dup[n+i] = ddown[N-1+n-i] = true;
		findQueen(n+1);
		arr[i] = dup[n+i] = ddown[N-1+n-i] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	
	arr = new bool[N];
	dup = new bool[2*N-1];
	ddown = new bool[2*N-1];
	
	findQueen(0);
	cout<<count;
	
	delete[] arr;
	delete[] dup;
	delete[] ddown;
	return 0;
}
