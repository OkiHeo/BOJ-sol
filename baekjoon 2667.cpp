#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm> 
#include <utility> 
using namespace std;

int N;					// 지도의 크기 
int area[26][26]={0,};	// 지도(인덱스 1~25 사용) 
int danji=0;			// 단지수 
queue<pair<int,int> > q; // 각 단지수를 인덱스로 사용. 단지별 집의 수
int numDanji[25*25/2+1]={0,};

// 입력받는 함수 
void input(){
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%1d", &area[i][j]);
		}
	}
} 

// 해당 위치가 지도 내부에 존재하는지 true, false 리턴 
bool inArea(int x, int y){
	return (x>=1&&x<=N&&y>=1&&y<=N);
}

// [x][y]집의 상하좌우를 체크하는데 사용하는 함수. 
void check(int x, int y){
	// x,y가 지도 내에 존재하고, [x][y]가 집이면 해당 단지의 큐에 넣고, danji+1 값 바꿔준다. 
	if( inArea(x, y) && area[x][y]==1 ){
			q.push(make_pair(x,y));
				area[x][y] = danji+1;
				numDanji[danji]++;
	}
}

void oneDanji(int i, int j){
	danji++;		// 한 단지의 집 하나 발견! 
	area[i][j] = danji+1;		// n단지의 집에는 n+1을 저장해준다.
	q.push(make_pair(i, j));
	numDanji[danji]++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		// 해당 집의 상하좌우 체크. 
		check(x-1, y);
		check(x, y-1);
		check(x, y+1);
		check(x+1, y);
	} 
	
}
// 문제를 해결하는 함수 
void findDanji(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			// 집이 있는 장소 찾으면 그 장소를 저장, 그 집이 포함된 단지 탐색 
			if( area[i][j]==1 ){
				oneDanji(i,j);
			}
		}
	}
	
	// 단지의 개수만큼 numDanji배열 오름차순 정렬. 
	sort(numDanji+1, numDanji+danji+1);
	// 단지의 개수 출력 
	cout<<danji<<'\n';
	// 각 단지별 집의 수 오름차순으로 출력. 
	for(int i=1; i<=danji; i++){
		cout<<numDanji[i]<<'\n';
	}
} 

int main(){
	input();
	findDanji();
	return 0;
}
