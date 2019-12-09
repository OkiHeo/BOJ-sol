/*
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

입력

첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력

첫째 줄에 답을 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
int n;
int sum[MAX];
int serial[MAX];

void input(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>serial[i];
	}
}

int solve(){
	// 첫 번째 원소로 가장 큰 연속합, 첫 번째 연속합 초기화. 
	int sumMax=serial[0];
	sum[0] = serial[0];
	for(int i=1; i<n; i++){
		// '현재 원소 < 이전 연속합 + 현재원소' 일 때 더 큰 것을 sum[i]로 저장. 
		sum[i] = max(sum[i-1]+serial[i], serial[i]);
		// 가장 큰 연속합을 갱신한다. 
		sumMax = max(sumMax, sum[i]);
	}
	return sumMax;
}

int main(){
	input();
	cout<<solve();
	return 0;
}
