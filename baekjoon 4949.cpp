#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	while(true){
		string s;
		stack<char> st;
		getline(cin, s);
		
		// '.'�� �Է¹����� �����Ѵ�. 
		if( s.length()==1 && s[0]=='.' )
			break;
			
		bool flag = true;
		// �Է¹��� ���ڿ��� ���̸�ŭ �ݺ�. ��� �ε��� �湮				
		for(int i=0; i<s.length(); i++){
			if( s[i]=='('){	// ���� ��ȣ ������ push 
				st.push('(');
			}
			else if( s[i]=='[' ){
				st.push('[');
			}
			else if( s[i]==')'){		// �ݴ°�ȣ )�������� 
				if( !st.empty()&&st.top()=='(' ){	// ���� top�� (�̸� ���� pop 
					st.pop();
				}
				else{
					flag = false;
					break;
				}
			}
			else if(s[i]==']'){			// �ݴ°�ȣ ]�������� 
				if( !st.empty() && st.top()=='['){	// ���� top�� [�̸� ���� pop 
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
