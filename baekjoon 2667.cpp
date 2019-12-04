#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm> 
#include <utility> 
using namespace std;

int N;					// ������ ũ�� 
int area[26][26]={0,};	// ����(�ε��� 1~25 ���) 
int danji=0;			// ������ 
queue<pair<int,int> > q; // �� �������� �ε����� ���. ������ ���� ��
int numDanji[25*25/2+1]={0,};

// �Է¹޴� �Լ� 
void input(){
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%1d", &area[i][j]);
		}
	}
} 

// �ش� ��ġ�� ���� ���ο� �����ϴ��� true, false ���� 
bool inArea(int x, int y){
	return (x>=1&&x<=N&&y>=1&&y<=N);
}

// [x][y]���� �����¿츦 üũ�ϴµ� ����ϴ� �Լ�. 
void check(int x, int y){
	// x,y�� ���� ���� �����ϰ�, [x][y]�� ���̸� �ش� ������ ť�� �ְ�, danji+1 �� �ٲ��ش�. 
	if( inArea(x, y) && area[x][y]==1 ){
			q.push(make_pair(x,y));
				area[x][y] = danji+1;
				numDanji[danji]++;
	}
}

void oneDanji(int i, int j){
	danji++;		// �� ������ �� �ϳ� �߰�! 
	area[i][j] = danji+1;		// n������ ������ n+1�� �������ش�.
	q.push(make_pair(i, j));
	numDanji[danji]++;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		// �ش� ���� �����¿� üũ. 
		check(x-1, y);
		check(x, y-1);
		check(x, y+1);
		check(x+1, y);
	} 
	
}
// ������ �ذ��ϴ� �Լ� 
void findDanji(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			// ���� �ִ� ��� ã���� �� ��Ҹ� ����, �� ���� ���Ե� ���� Ž�� 
			if( area[i][j]==1 ){
				oneDanji(i,j);
			}
		}
	}
	
	// ������ ������ŭ numDanji�迭 �������� ����. 
	sort(numDanji+1, numDanji+danji+1);
	// ������ ���� ��� 
	cout<<danji<<'\n';
	// �� ������ ���� �� ������������ ���. 
	for(int i=1; i<=danji; i++){
		cout<<numDanji[i]<<'\n';
	}
} 

int main(){
	input();
	findDanji();
	return 0;
}
