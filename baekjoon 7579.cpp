#include <iostream>
#include <vector>
using namespace std;

int n, M;
vector<int> mem;
vector<int> cost;
int d[10001]; 
	// d[cost]에 cost를 만족하는 최대로 확보 가능한 메모리 크기를 저장한다. 



int main(){
	// 입 력 
	cin>>n>>M;
	for(int i=0; i<n; i++){
		int m;
		cin>>m;
		mem.push_back(m);
	}
	for(int i=0; i<n; i++){
		int c;
		cin>>c;
		cost.push_back(c);
	}
	// d배열 값을 모두 -1로 초기화
	fill_n(d, 10001, -1); 
	
	// 필요한 메모리 M바이트를 확보하기 위한 앱 비활성화의 최소비용 계산.
	for(int i=0; i<n; i++){
		int c = cost[i];
		for(int j=10000; j>=c; j--){
			if( d[j-c]==-1 ) continue;	// 계산된적있는 j-c에 대해서만 계산 
			d[j] = max(d[j], d[j-c]+mem[i]);
			// i번째 app을 포함하는 경우와 포함하지 않는 경우 중 확보 메모리가 더 큰 경우 저장. 
		}
		if( d[c]<mem[i] ) d[c] = mem[i];
	}
	for(int i=0; i<10001; i++){
		if( d[i] >= M ){
		// 작은 cost부터 탐색, 최초로 확보 메모리가 M 이상인 경우 cost 출력 
			cout<<i<<'\n';
			return 0;
		}
	}
}
