#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
 
int N, K;
bool visit[100001];
int sec=0;
queue<int> q;

void input(){
	// ������ ��ġ N, ���� ��ġ K�� �Է¹޴´�. 
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
			
			// x-1, x+1, x*2�� üũ�Ѵ�. 
			int check[3] = {now-1, now+1, now*2};
			for(int i=0; i<3; i++)
				// �� ��ġ�� ���� ���� �����ϸ� �湮���� ������ �湮. 
				if( check[i] >=0 && check[i]<=100000){
					if( visit[check[i]]==true ) continue;
					visit[check[i]] = true;
					// �� ��ġ���� ������ �����ٸ� �ɸ� �ð� ����! 
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
