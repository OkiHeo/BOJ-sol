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

vector<int> dijkstra(int start){
	// start ���� �����ؼ� �� �������� ���� �ִܰŸ� ���Ѵ�� �ʱ�ȭ. 
// vector�� �����ϵ��� �����غ��Ҵ�. 
	vector<int> shortest(801, INF);
	
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
// start���� �ٸ� ��� ���������� �ִܰŸ��� ������ ������ü�� ������. 
	return shortest;
}

int solve(){
	vector<int> sStart = dijkstra(1);
	int startToOne = sStart[one];
	int startToTwo = sStart[two];
	
	vector<int> sOne = dijkstra(one);
	int oneToTwo = sOne[two];
	// one->two�� two->one�� �����ϹǷ� �ѹ��� ���. 
	
	vector<int> sEnd = dijkstra(N);
	int twoToEnd = sEnd[two];
	int oneToEnd = sEnd[one];

	// �� ���� ����� ����� ����. 
	int result1=0, result2=0;	
	result1 = startToOne+oneToTwo+twoToEnd;		// ���1�� ��� 
	result2 = startToTwo+oneToTwo+oneToEnd;		// ���2�� ��� 
	
//������ �κ�! 
	int result = min(result1, result2);
	if( result>=INF )	return -1;
	else return result;
}

int main(){
	input();
	printf("%d\n", solve());
	return 0;
}
