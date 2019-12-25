#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *nums = new int[n+1];
	for(int i=1; i<=n; i++){
		cin>>nums[i];		// 인덱스 1~n 사용 
	}
	
	// 1~n의 수열을 만들어보자
	// 스택에 push 하는 순서는 반드시 오름차순을 지킨다
	// 임의의 수열을 스택을 이용해 그 수열을 만들 수 있으면push/pop연산 출력해서 표현하고
	// 만들수없으면 NO를 출력한다.
	stack<int> st;
	queue<char> q;
	int i=1, j=1;
	while(i!=n && j!=n){
		// 스택이 비어있지 않고,
		// nums[j]가 스택의 맨 위에 있는 수와 같다면 pop 
		if( i>nums[j] ){
			if( nums[j] < st.top() ){
				cout<<"NO\n";
				return 0;
			}
			while( !st.empty() && nums[j]==st.top() ){
				st.pop();
				q.push('-');
				j++;
			}
		}
		// 스택에 nums[j]에 해당하는 수까지 push한다. 
		if( i<nums[j] )
		while(true){
			if( nums[j]<i ) break;
			st.push(i);
			q.push('+');
			i++;
		}
	}
	while(!q.empty()){
		cout<<q.front()<<'\n';
		q.pop();
	}
	return 0;
}
