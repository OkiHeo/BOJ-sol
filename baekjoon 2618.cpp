#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct point{
	int x, y;
}point;
int n, w;

int dp[1004][1004];		// dp[x][y]는 경찰차1,2가 x, y번째 사건 담당시 이동한 최소거리 저장 
point arr[1004];		// 발생한 사건 좌표 입력. 

// 두 좌표간의 맨해튼 거리를 리턴하는 함수. 
int dist(point one, point two){
	return abs(one.x-two.x)+abs(one.y-two.y);
} 

int cal(int c1, int c2){
	int curr = max(c1, c2);	// 현재 몇번째 사건까지 처리했는가
	// w+1번째 사건까지 모두 처리한 후에 w+2번째 사건을 처리하려고 하면 종료한다. 
	if( curr == w+2 ) return 0; 
	// c1, c2사건을 처리한 결과가 존재한다면 리턴 
	if( dp[c1][c2] != -1 ) return dp[c1][c2];
	
	// case1. 1번 경찰차가 다음 사건 처리
	int case1 = cal(curr+1, c2)+dist(arr[curr+1], arr[c1]);
	// case2. 2번 경찰차가 다음 사건 처리
	int case2 = cal(c1, curr+1)+dist(arr[curr+1], arr[c2]);	 
	return dp[c1][c2] = min(case1, case2);
} 

void printSelected(int c1, int c2){
	int curr = max(c1, c2);
	if( curr == w+2 ) return;
	
	int case1 = cal(curr+1, c2)+dist(arr[curr+1], arr[c1]);
	int case2 = cal(c1, curr+1)+dist(arr[curr+1], arr[c2]);
	
	// 1번 경찰차를 선택하는 경우가 되므로. 1출력. 1번 경찰차를 선택한 경우 그 이하의 케이스에 대해 조사. 
	if( case1<case2 ){
		cout<<"1\n";
		printSelected(curr+1, c2);
	}
	else{
		cout<<"2\n";
		printSelected(c1, curr+1);
	} 
}
int main(){
	cin>>n>>w;
	arr[1].x=arr[1].y=1;	// 1번 경찰차(1,1), 2번경찰차(n,n)에서 출발 
	arr[2].x=arr[2].y=n;

	// w개의 사건 발생 좌표 입력 (3~w+2번 사건) 
	for(int i=0; i<w; i++){
		cin>>arr[3+i].x>>arr[3+i].y;
	}
	
	// dp배열을 -1로 초기화한다. 
	for(int i=0; i<1004; i++){
		for(int j=0; j<1004; j++){
			dp[i][j]=-1;
		}
	}
	
	cout<<cal(1,2)<<'\n';
	printSelected(1,2);
	cout<<"------------------------------\n";
	for(int i=0; i<=w+2; i++){
		for(int j=0; j<=w+2; j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<"\n";
	} 
	
	return 0;
}
