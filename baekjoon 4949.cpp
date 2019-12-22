#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	while(true){
		string s;
		stack<char> st;
		getline(cin, s);
		
		// '.'만 입력받으면 종료한다. 
		if( s.length()==1 && s[0]=='.' )
			break;
			
		bool flag = true;
		// 입력받은 문자열의 길이만큼 반복. 모든 인덱스 방문				
		for(int i=0; i<s.length(); i++){
			if( s[i]=='('){	// 여는 괄호 만나면 push 
				st.push('(');
			}
			else if( s[i]=='[' ){
				st.push('[');
			}
			else if( s[i]==')'){		// 닫는괄호 )만났을때 
				if( !st.empty()&&st.top()=='(' ){	// 스택 top이 (이면 스택 pop 
					st.pop();
				}
				else{
					flag = false;
					break;
				}
			}
			else if(s[i]==']'){			// 닫는괄호 ]만났을때 
				if( !st.empty() && st.top()=='['){	// 스택 top이 [이면 스택 pop 
					st.pop();
				}
				else{
					flag = false;
					break;
				}
			}
		}
		
		if( flag && st.empty() )
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}
