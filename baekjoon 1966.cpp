#include <iostream>
#include <queue> 
using namespace std;

int tc, m, n; 

int main(){
	cin>>tc;
	for(int t=0; t<tc; t++){
		cin>>n>>m;
		// ������ �߿䵵 ū�ͺ��� �������� ����.
		priority_queue<int> pq; 
		// ���� ��ȣ, �߿䵵 ����. 
		queue<pair<int, int> > q;
		
		// n�� ������ �߿䵵�� ������� �Է�. 
		for(int d=0; d<n; d++){
			int priority;
			cin>>priority;
			q.push(make_pair(d, priority));
			pq.push(priority);
		}
		int printnum=0;
		
		// m ������ �� ��°�� ��µ��� ã��.
		while(!q.empty()){
			// ���� ť�� �� �տ� �ִ� ���� ��. 
			int nowdoc = q.front().first;
			int nowprio = q.front().second;
			q.pop();
			// ���� ���� �� �߿䵵 ���� ū�Ͱ� ��.
			// �߿䵵 ���� ū ������ ���� ť�� �� �տ� �־��ٸ� 
			if( pq.top()==nowprio){
				printnum++;		// ����Ʈ 
				pq.pop();		// pq���� ���� 
				if( nowdoc == m ){
					// ���� ����Ʈ �� ������ �ε��� m�̶��
					// ���°�� �μ�Ǵ��� ��� 
					cout<<printnum<<'\n';
					break;
				}
			}
			// �߿䵵 ���� ū ������ �ƴ϶�� �ٽ� ť�� �� �ڷ� �־��ش�. 
			else{
				q.push(make_pair(nowdoc, nowprio));
			}
		}
	}
	return 0;
}
