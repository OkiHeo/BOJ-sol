#include <iostream>
#include <queue> 
using namespace std;

int tc, m, n; 

int main(){
	cin>>tc;
	for(int t=0; t<tc; t++){
		cin>>n>>m;
		// 문서의 중요도 큰것부터 나오도록 저장.
		priority_queue<int> pq; 
		// 문서 번호, 중요도 저장. 
		queue<pair<int, int> > q;
		
		// n개 문서의 중요도를 순서대로 입력. 
		for(int d=0; d<n; d++){
			int priority;
			cin>>priority;
			q.push(make_pair(d, priority));
			pq.push(priority);
		}
		int printnum=0;
		
		// m 문서가 몇 번째에 출력될지 찾자.
		while(!q.empty()){
			// 현재 큐의 맨 앞에 있는 문서 비교. 
			int nowdoc = q.front().first;
			int nowprio = q.front().second;
			q.pop();
			// 남은 문서 중 중요도 제일 큰것과 비교.
			// 중요도 제일 큰 문서가 현재 큐의 맨 앞에 있었다면 
			if( pq.top()==nowprio){
				printnum++;		// 프린트 
				pq.pop();		// pq에서 제거 
				if( nowdoc == m ){
					// 현재 프린트 한 문서가 인덱스 m이라면
					// 몇번째로 인쇄되는지 출력 
					cout<<printnum<<'\n';
					break;
				}
			}
			// 중요도 제일 큰 문서가 아니라면 다시 큐의 맨 뒤로 넣어준다. 
			else{
				q.push(make_pair(nowdoc, nowprio));
			}
		}
	}
	return 0;
}
