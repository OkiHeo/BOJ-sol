#include <iostream>
using namespace std;

int n, m, p;
bool visit[100001];
int hateToFav[100001];

int search(int now){
	// 현재 채널을 방문처리. 
	visit[now] = true;
	// 현재 채널을 싫어하는 사람이 바꿀 채널을 next에 저장. 
	int next = hateToFav[now];
	// next==0은 현재 채널을 싫어하는 사람이 없다는 뜻. 
	if( next == 0 ) return 0;
	
	// next 채널에 방문한 적 있다면 앞으로도 사이클을 돌 것.
	// -1을 출력해준다. 
	if( visit[next] ){
		return -1;
	}
	
	// 다음 채널을 기준으로 싫어하는 사람이 채널을 돌리도록 deep하게 탐색. 
	int deep = search(next);
	// 그 다음에 사이클이 발생하면 -1을 출력하고, 사이클이 발생하지 않는다면 채널 변경 횟수 1 추가. 
	return deep==-1?-1:deep+1;
}

int main(){
	cin>>n>>m>>p;
	
	for(int i=0; i<n; i++){
		int fav, hate;
		cin>>fav>>hate;
		// 먼저 입력된 사람의 선호(=어린 사람의 선호)
		// 싫어하는 채널이 같은 사람이 여러 명이라면 그 중 가장 먼저 입력된 사람이 채널을 바꾸므로. 
		if( hateToFav[hate]==0 )
			hateToFav[hate] = fav;
	}
	
	cout<<search(p);
	return 0;
}
