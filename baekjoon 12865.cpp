#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int> > item;
int d[100][100001];						// 인덱스 0~99 사용 

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
	// 이 값이 이미 계산된 값이라면 저장된 값을 리턴 
	if( tmp != 0 ) return tmp;
	
	// 여유무게 >= 이번 아이템 무게일때
	// 이번 아이템을 담는 선택 vs 담지 않는 선택 중 value가 최대가 되는 선택을 한다. 
	if( cap>=item[cur].first ){
		tmp = max( knapsack(cur+1, cap-item[cur].first)+item[cur].second,
					knapsack(cur+1, cap));
	}
	// 여유무게 < 이번 아이템 무게이면
	// 이 아이템은 절대로 담을 수없으므로 다음 아이템을 탐색한다. 
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
