#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, E;
int one, two;
vector< pair<int, int> > node[801];
int INF = 800001;

void input(){
	//  ������ ����, ������ ���� �Է� 
	scanf("%d %d", &N, &E);
	// �׷��� �Է� 
	for(int i=0; i<E; i++){
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		// ����� �׷���! 
		node[start].push_back(make_pair(end, cost));
		node[end].push_back(make_pair(start, cost));
	}
	// �ݵ�� ���ľ� �ϴ� �� ���� ���� �ٸ� ���� ��ȣ 
	scanf("%d %d", &one, &two);
}

int dijkstra(int start, int end){
	// start ���� �����ؼ� �� �������� ���� �ִܰŸ� ���Ѵ�� �ʱ�ȭ. 
	long long int shortest[801];
	fill_n(shortest, 801, INF);
	
	priority_queue< pair<int, int> > pq;
	// �켱���� ť�� ���� ���� push.  
	pq.push(make_pair(0, start));
	shortest[start] = 0; 
	
	while(!pq.empty()){
		// ���� ��ġ�� ������ ���� Ž��. 
		int now = pq.top().second;
		int nowcost = -pq.top().first;
		pq.pop();
		// �˰� �ִ� start->now �ִܰŸ����� nowcost�� ũ�� �� ������ �н� 
		if( shortest[now] < nowcost ) continue;
		
		// now�� �����ؼ� �� �� �ִ� ������ �����ؼ� ���� �Ÿ��� �� ª�ٸ� ��ü. 
		for( int i=0; i<node[now].size(); i++){
			int next = node[now][i].first;
			int nextcost = node[now][i].second + nowcost;
			
			if( shortest[next] > nextcost ){
				shortest[next] = nextcost;
				pq.push(make_pair(-nextcost, next));
				// �켱���� ť�� ����ϹǷ� cost�� ����ȭ�ؼ� �����ؾ� �����ͺ��� ���� �� �ִ�. 
			}
		}
	}

	// end������ �ִܰŸ� ������ �ȵǾ��ٸ� -1�� �����Ѵ�. 
	if( shortest[end] >= INF ) return -1;
	// end������ �ִܰŸ��� �����Ѵٸ� �� �Ÿ��� ���� 
	else	return shortest[end];
}

int solve(){
	int startToOne = dijkstra(1, one);
	int startToTwo = dijkstra(1, two);
	int oneToTwo = dijkstra(one, two);
	int twoToEnd = dijkstra(two, N);
	int oneToEnd = dijkstra(one, N);
	int result1=0, result2=0;
	bool flag1 = true, flag2 = true;
	// ��� �� �ϳ��� �ִܰŸ��� ã�� ���ϴ� ��ΰ� �ִٸ� -1�� ����Ѵ�. 
	// ��� 1�� : 1->one->two->N
	if( startToOne==-1 || oneToTwo==-1 || twoToEnd==-1 ){
		flag1 = false;
	}
	// ��� 2�� : 1->two->one->N
	if( startToTwo==-1 || oneToTwo==-1 || oneToEnd==-1 ){
		flag2 = false;
	}

	result1 = startToOne+oneToTwo+twoToEnd;		// ���1�� ��� 
	result2 = startToTwo+oneToTwo+oneToEnd;		// ���2�� ��� 

	// ��� 1��, ��� 2�� ��� �Ұ��� �� �� 
	if( !flag1 && !flag2 ){
		return -1; 
	}
	// ��� 1�� �����Ҷ� 
	else if( flag1 && !flag2 ){
		return result1;
	}
	// ��� 2�� �����Ҷ� 
	else if( flag2 && !flag1){
		return result2;
	}
	// ��� 1�� 2 ��� ������ �� 
	else{
		return min(result1, result2);
	}
}
int main(){
	input();
	printf("%d\n", solve());
	return 0;
}
