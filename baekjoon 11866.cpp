#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	queue<int> q;
	
	// 1~n������ ���� ť�� push 
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	
	cout<<'<';
	while(true){
		for(int i=1; i<=k; i++){
			int tmp = q.front();
			q.pop();
			if(i!=k){
				q.push(tmp);
			}
			else{
				cout<<tmp;
				if( !q.empty())cout<<", ";
			}
		}
		if( q.empty()) break;
	}
	cout<<'>';

	return 0;
} 
