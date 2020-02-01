#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct point{
	int x, y;
}point;
int n, w;

int dp[1004][1004];		// dp[x][y]�� ������1,2�� x, y��° ��� ���� �̵��� �ּҰŸ� ���� 
point arr[1004];		// �߻��� ��� ��ǥ �Է�. 

// �� ��ǥ���� ����ư �Ÿ��� �����ϴ� �Լ�. 
int dist(point one, point two){
	return abs(one.x-two.x)+abs(one.y-two.y);
} 

int cal(int c1, int c2){
	int curr = max(c1, c2);	// ���� ���° ��Ǳ��� ó���ߴ°�
	// w+1��° ��Ǳ��� ��� ó���� �Ŀ� w+2��° ����� ó���Ϸ��� �ϸ� �����Ѵ�. 
	if( curr == w+2 ) return 0; 
	// c1, c2����� ó���� ����� �����Ѵٸ� ���� 
	if( dp[c1][c2] != -1 ) return dp[c1][c2];
	
	// case1. 1�� �������� ���� ��� ó��
	int case1 = cal(curr+1, c2)+dist(arr[curr+1], arr[c1]);
	// case2. 2�� �������� ���� ��� ó��
	int case2 = cal(c1, curr+1)+dist(arr[curr+1], arr[c2]);	 
	return dp[c1][c2] = min(case1, case2);
} 

void printSelected(int c1, int c2){
	int curr = max(c1, c2);
	if( curr == w+2 ) return;
	
	int case1 = cal(curr+1, c2)+dist(arr[curr+1], arr[c1]);
	int case2 = cal(c1, curr+1)+dist(arr[curr+1], arr[c2]);
	
	// 1�� �������� �����ϴ� ��찡 �ǹǷ�. 1���. 1�� �������� ������ ��� �� ������ ���̽��� ���� ����. 
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
	arr[1].x=arr[1].y=1;	// 1�� ������(1,1), 2��������(n,n)���� ��� 
	arr[2].x=arr[2].y=n;

	// w���� ��� �߻� ��ǥ �Է� (3~w+2�� ���) 
	for(int i=0; i<w; i++){
		cin>>arr[3+i].x>>arr[3+i].y;
	}
	
	// dp�迭�� -1�� �ʱ�ȭ�Ѵ�. 
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
