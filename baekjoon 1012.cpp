#include <iostream>
#include <queue>
using namespace std;

int T;
int M, N, K, X, Y;
int area[50][50];		// �ε��� 0~49 ���. ���߹� 
int cnt;				// �������������� ��  
queue<int> q;			// ������ x��ǥ*N+y��ǥ�� �����ؼ� ����. 

void worm(int i, int j){
	cnt++;
	area[i][j] = cnt+1;	// 1�� �ƴ� ���� �ٲ��ֱ� ���� cnt+1���� �ٲ��ش�. 
	q.push(i*N+j);		// ������ x��ǥ�� y��ǥ�� �����ؼ� ť�� Ǫ�� 
	
	while(!q.empty()){
		int newx = q.front()/N;
		int newy = q.front()%N; 
		q.pop();
		area[newx][newy] = cnt+1;	// �ٽ� ��ã���� ���߸� cnt+1�� �ٲ��ش�.

		if( newx-1>=0 &&area[newx-1][newy]==1 ){	// �� 
			q.push((newx-1)*N+newy);
			area[newx-1][newy] = cnt+1;	
		}
		if( newy-1>=0 &&area[newx][newy-1]==1 ){	// �� 
			q.push(newx*N+(newy-1));
			area[newx][newy-1] = cnt+1;	
		}
		if( newy+1<N &&area[newx][newy+1]==1 ){		// �� 
			q.push(newx*N+newy+1);
			area[newx][newy+1] = cnt+1;	
		}
		if( newx+1<M &&area[newx+1][newy]==1 ){		// �� 
			q.push((newx+1)*N+newy);
			area[newx+1][newy] = cnt+1;	
		}
	}
}

void solve(){
	// ���߹� ó������ ���߰� �ɾ��� ��ġ�� ã�´�. 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			// ���� ã���� �� ���߿� �̾����ִ� ���� ������ ã�´� 
			if( area[i][j]==1 ){
				worm(i, j);
			}
		}
	}
}

int main(){
	cin>>T;	// �׽�Ʈ���̽� �Է�. �׽�Ʈ���̽� �� ��ŭ �ݺ� 
	for(int t=0; t<T; t++){
		// ���߹�, ������ �� 0���� �ʱ�ȭ. 
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				area[i][j] = 0;
			}
		}
		cnt=0;
		
		// ���߹��� ����, ���� ũ��, ���� ���� �Է¹޴´�. 
		cin>>M>>N>>K;
		// ������ ������ŭ ��ġ �Է¹ް� ���� �ɴ´�! 
		for(int k=0; k<K; k++){
			cin>>X>>Y;
			area[X][Y]=1;
		}
		
		// �ʿ��� ������������ ���� ����. 
		solve();
		cout<<cnt<<'\n'; 
	}
	return 0;
}
