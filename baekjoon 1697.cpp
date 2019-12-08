#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
 
int N, K;
bool visit[100001];
int sec=0;
queue<int> q;

void input(){
	// 수빈이 위치 N, 동생 위치 K를 입력받는다. 
	scanf("%d %d", &N, &K);
}

int solve(){
	q.push(N);
	visit[N] = true;
	if (K<=N){
		return N-K;
	} 
	while(!q.empty()){
		sec++;
		int size = q.size();
		for(int i=0; i<size; i++){
			int now = q.front();
			q.pop();
			
			// x-1, x+1, x*2를 체크한다. 
			int check[3] = {now-1, now+1, now*2};
			for(int i=0; i<3; i++)
				// 새 위치가 범위 내에 존재하면 방문하지 않은곳 방문. 
				if( check[i] >=0 && check[i]<=100000){
					if( visit[check[i]]==true ) continue;
					visit[check[i]] = true;
					// 새 위치에서 동생을 만난다면 걸린 시간 리턴! 
					if( check[i] == K ) return sec;
					q.push(check[i]);
				}
		}
	}
}

int main(){
	input();
	cout<< solve();
	return 0;
}
