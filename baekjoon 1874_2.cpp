#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int nums[100000];
// c/c++에서는 a[100000] 크기의 배열을 지역변수로 선언할 수 없다고해서 전역변수로 선언 
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>nums[i];		// 인덱스 1~n 사용 
	}
	
	// 1~n의 수열을 만들어보자
	// 스택에 push 하는 순서는 반드시 오름차순을 지킨다
	// 임의의 수열을 스택을 이용해 그 수열을 만들 수 있으면push/pop연산 출력해서 표현하고
	// 만들수없으면 NO를 출력한다.
	stack<int> st;
	queue<char> q;	// '+'와 '-'를 저장한다. 
	int i=1, j=0;
	
	// 1부터 n까지의 수를 차례로 스택에 push하면서
	// 수열 현재값과 같으면 스택에서 pop하는 방식으로 비교해나간다. 
	for(int i=1; i<=n; i++){
		st.push(i);
		q.push('+');
		// 스택의 최상단과 수열 현재값 같으면
		// 비교하고, 스택에서 pop할 수 있는만큼 pop한다 
		while( !st.empty()&&st.top()==nums[j] ){
			st.pop();
			q.push('-');
			j++;
		}
	}
	
	// n까지 스택에 push 후에 수열과 같다면 pop하는 방식에서
	// 스택에 값이 남아있다면 해당 수열을 스택을 이용해서 만들수없다는 뜻 
	if( !st.empty() ){
		cout<<"NO\n";
		return 0;
	}
	// 스택이 비어있다면 해당 수열을 만들수 있다는 뜻
	// 큐에 저장된 것을 출력한다. 
	else{
		while(!q.empty()){
			cout<<q.front()<<'\n';
			q.pop();
		}
	}
	return 0;
}
