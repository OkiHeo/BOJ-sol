#include <iostream>
#include <queue>
using namespace std;

int T;
int M, N, K, X, Y;
int area[50][50];		// 인덱스 0~49 사용. 배추밭 
int cnt;				// 배추흰지렁이의 수  
queue<int> q;			// 배추의 x좌표*N+y좌표로 압축해서 저장. 

void worm(int i, int j){
	cnt++;
	area[i][j] = cnt+1;	// 1이 아닌 수로 바꿔주기 위해 cnt+1으로 바꿔준다. 
	q.push(i*N+j);		// 배추의 x좌표와 y좌표를 압축해서 큐에 푸시 
	
	while(!q.empty()){
		int newx = q.front()/N;
		int newy = q.front()%N; 
		q.pop();
		area[newx][newy] = cnt+1;	// 다시 안찾도록 배추를 cnt+1로 바꿔준다.

		if( newx-1>=0 &&area[newx-1][newy]==1 ){	// 상 
			q.push((newx-1)*N+newy);
			area[newx-1][newy] = cnt+1;	
		}
		if( newy-1>=0 &&area[newx][newy-1]==1 ){	// 좌 
			q.push(newx*N+(newy-1));
			area[newx][newy-1] = cnt+1;	
		}
		if( newy+1<N &&area[newx][newy+1]==1 ){		// 우 
			q.push(newx*N+newy+1);
			area[newx][newy+1] = cnt+1;	
		}
		if( newx+1<M &&area[newx+1][newy]==1 ){		// 하 
			q.push((newx+1)*N+newy);
			area[newx+1][newy] = cnt+1;	
		}
	}
}

void solve(){
	// 배추밭 처음부터 배추가 심어진 위치를 찾는다. 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			// 배추 찾으면 그 배추에 이어져있는 배추 묶음을 찾는다 
			if( area[i][j]==1 ){
				worm(i, j);
			}
		}
	}
}

int main(){
	cin>>T;	// 테스트케이스 입력. 테스트케이스 수 만큼 반복 
	for(int t=0; t<T; t++){
		// 배추밭, 지렁이 수 0으로 초기화. 
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				area[i][j] = 0;
			}
		}
		cnt=0;
		
		// 배추밭의 가로, 세로 크기, 배추 개수 입력받는다. 
		cin>>M>>N>>K;
		// 배추의 개수만큼 위치 입력받고 배추 심는다! 
		for(int k=0; k<K; k++){
			cin>>X>>Y;
			area[X][Y]=1;
		}
		
		// 필요한 배추흰지렁이 수를 센다. 
		solve();
		cout<<cnt<<'\n'; 
	}
	return 0;
}
