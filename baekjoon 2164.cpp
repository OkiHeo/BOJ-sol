#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
	cin>>n;
	queue<int> q;
	for(int i=1; i<=n; i++)
		q.push(i);
	while(q.size()!=1){
		q.pop();
		int item = q.front();
		q.pop();
		q.push(item);
	}
	cout<<q.front()<<'\n';
	return 0;
}
