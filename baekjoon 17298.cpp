#include <iostream>
#include <stack>
using namespace std;

int n;
int a[1000001];			// 인덱스 1~1,000,000을 사용한다 

int main(){
	cin>>n;
	stack<int> st;
	// 오큰수를 판별할 수들을 a[i]에 저장한다. 
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	// 수열에 들어갈 수 있는 어느 원소보다 큰 값을 스택에 push 
	st.push(1000002);
	// 수열을 뒤에서부터 앞으로 탐색한다. 
	for(int i=n; i>0; i--){
		// 스택의 top에 현재 수열값보다 작은 값이 있다면
		// 더 큰 수가 나올때까지 pop한다.
		// -> 현재 수열값 뒤쪽에 존재하는 가장 최근의 더 큰 값이 나온다. 
		if( st.top()<=a[i] ){
			while(true){
				st.pop();
				if( st.top()>a[i] ) break;
			}
		}
		// 앞에서 더 작은값이 존재해서 pop연산 진행 후에
		// 바로 a[i]의 오큰수 판단을 위해서 else대신 if문을 사용.
		// 스택 top값 > 수열값이면
		// tmp에 a[i]값을 보관. 
		// a[i]에 a[i]의 오큰수(스택의 top값)를 저장하고
		// tmp에 보관해둔 a[i]를 스택에 push한다. 
		if( st.top()>a[i]){
			int tmp=a[i]; 
			if( st.top()==1000002 ){
				a[i] = -1;
			}
			else{
				a[i] = st.top();
			}
			st.push(tmp);
		}
	}
	
	// 수열의 오큰수를 출력한다. 
	for(int i=1; i<=n; i++){
		cout<<a[i]<<' ';
	}
	
	return 0;
}
