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
	queue<char> q;
	int i=1, j=0;
	
	while( j<n ){
		// 스택이 비어있지않고 top==nums[j]일때 
		while( !st.empty() && st.top() == nums[j] ){
			st.pop();
			q.push('-');
			j++;
		}
		// nums[j]까지의 수(i)를 스택에 push한다.
		if( nums[j]>=i ){
			while(true){
				if( nums[j]<i ) break;
				st.push(i);
				q.push('+');
				i++;	
			}
		}
		// nums[j]까지의 수가 이미 스택에 들어갔는데
		// 스택이 비어있지않고, top에 존재하는 수가 nums[j]보다 크다면
		// 이 수열은 스택을 이용해서 만들 수 없으므로 NO를 출력 
		else if( !st.empty() && st.top()>nums[j] ){
			cout<<"NO\n";
			return 0;
		}
	}
	while(!q.empty()){
		cout<<q.front()<<'\n';
		q.pop();
	}
	return 0;
}
