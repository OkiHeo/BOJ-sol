#include <iostream>
#include <cmath>
using namespace std;

int n;
int wine[10001];			// 각 포도주잔에 들어있는 포도주의 양 저장 
int wineSum[10001]={0,};	// i번째 포도주잔까지 마실때 최대로 마실수있는 포도주의 양 

void input(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>wine[i];
	}
}
int choose(){
	wineSum[0]=0;
	wineSum[1] = wine[1];
	wineSum[2] = wine[1]+wine[2];
	for(int i=3; i<=n; i++){
		// oox 경우와 oxo경우, xoo경우 중 최대 
		wineSum[i] = max( wineSum[i-1], wineSum[i-2]+wine[i] ); 
		wineSum[i] = max( wineSum[i], wineSum[i-3]+wine[i-1]+wine[i]);
	}
	return wineSum[n];
}

int main(){
	input();
	cout<<choose();
	return 0;
}
