#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int> > item;
int d[100][100001];						// �ε��� 0~99 ��� 

void input(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		int w, v;
		scanf("%d %d", &w, &v);
		item.push_back(make_pair(w, v));
	}
}

int knapsack(int cur, int cap){
	if( cur == n ) return 0;
	int tmp = d[cur][cap];
	// �� ���� �̹� ���� ���̶�� ����� ���� ���� 
	if( tmp != 0 ) return tmp;
	
	// �������� >= �̹� ������ �����϶�
	// �̹� �������� ��� ���� vs ���� �ʴ� ���� �� value�� �ִ밡 �Ǵ� ������ �Ѵ�. 
	if( cap>=item[cur].first ){
		tmp = max( knapsack(cur+1, cap-item[cur].first)+item[cur].second,
					knapsack(cur+1, cap));
	}
	// �������� < �̹� ������ �����̸�
	// �� �������� ����� ���� �������Ƿ� ���� �������� Ž���Ѵ�. 
	else{
		tmp = knapsack(cur+1, cap);
	}
	return d[cur][cap] = tmp;
}

void solve(){
	printf("%d\n", knapsack(0, k));
}

int main(){
	input();
	solve();
	return 0;
}
