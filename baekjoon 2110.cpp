#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int house[200001]; 
int mingap = 987654321;

void install(){ 
	int low = 1;
	int high = house[n]-house[1];
	long long int gap;
	long long int maxgap=0;
	
	while( low<=high ){
		gap = (low+high)/2;
		int cnt=1;
		int prev=1;		// 직전에 공유기 설치한 집 인덱스 
		
		for(int i=2; i<=c; i++){
		// 1번 집에는 무조건 공유기 설치.
		// 앞으로 2번째, ... c번째의 공유기를 설치한다. 
			for(int j=prev+1; j<=n; j++){
			// 이전에 공유기 설치했던 다음 집부터 탐색. 
				if( house[prev]+gap <= house[j] ){
					cnt++;
					prev = j;
					break;
				}
			}
		}
		
		if( cnt >= c ){
			// gap을 조금 더 늘려봐도 되겠다! 
			low = gap+1;
			maxgap = gap;		// 이전의 gap은 저장. 
		}
		else{
			high = gap-1;
		}
	}
	cout<<maxgap<<'\n';
	return;
}

int main(){
	cin>>n>>c;
	for(int i=1; i<=n; i++){
		cin>>house[i];
	}
	// 입력받은 집의 위치 오름차순 정렬. 
	sort(house, house+n+1);
	
	// 1번째집에는 공유기가 반드시 설치되어야
	// 두 공유기 사이의 거리를 최대로 할 수 있다.
	install();
	return 0; 
} 
