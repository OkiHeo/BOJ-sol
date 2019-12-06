#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
string ch;
stack<char> st;

bool vps(string ch){
	for(int i=0; i<ch.length(); i++){	// ch의 문자 하나하나를 탐색 
		if( ch[i]=='(' ){
			st.push('(');		// (를 만나면 스택에 넣고 
		}
		else if( ch[i]==')' ){
			if( !st.empty() )	// )를 만나면 스택이 비지 않은 한 pop한다. 
				st.pop();
			else
				return false;
				// )를 만났는데 스택이 비어있다면 전에 (이 없다는 것.
				// 결과는 false이다. 
		}
	}
	bool flag = st.empty();			// flag에 결과를 저장 
	while(!st.empty())st.pop();		// 다음 케이스를 위해 스택을 비워야한다 
	return flag;
}

int main(){
	cin>>T;
	for(int i=0; i<T; i++){
		// 괄호 문자열을 입력받는다. 
		cin>>ch;
		if( vps(ch) ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
} 
