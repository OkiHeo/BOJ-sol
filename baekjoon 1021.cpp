#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;
int count=0;

void pop(){
	dq.pop_front();
}
void right(){
	// 우측 순환 회전 <<-
	dq.push_back(dq.front());
	dq.pop_front();
	count++;
}
void left(){
	// 좌측 순환 회전 ->>
	dq.push_front(dq.back());
	dq.pop_back();
	count++;
}

int main(){
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
		dq.push_back(i);
	
	for(int i=0; i<m; i++){
		int num;
		cin>>num;
		
		// 바로 front에서 num을 뽑아낼 수 있다면 뽑아낸다. 
		if( dq.front()==num ){
			pop();
			continue;
		}
		
		int idx=0;
		// 지금 입력받은 num이 dq의 몇 번째에 위치하는지 찾는다.
		for(int i=0; i<dq.size(); i++){
			if( dq[i]==num){
				idx=i;
				break;
			}
		}
		
		// 좌측으로 회전시키는것, 우측으로 회전시키는 것 중
		// 어느 쪽이 더 빠른지 계산
		if( idx <= dq.size()-idx ){
			// 앞에서부터 세는 것이 빠른 경우
			// 우측 순환 회전 시키며 front 같을 때까지 찾는다. 
			while(true){
				right(); 
				if( dq.front()==num ){
					pop();
					break;
				}
			}
		}
		else{
			// 뒤에서부터 세는 것이 빠른 경우
			// 좌측 순환 회전 시키며 front 같을 때까지 찾는다. 
			while(true){
				left();
				if( dq.front()==num){
					pop();
					break;
				}
			}
		}
	}
	cout<<count<<'\n';
	return 0;
	
}
