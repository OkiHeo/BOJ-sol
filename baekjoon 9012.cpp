#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
string ch;
stack<char> st;

bool vps(string ch){
	for(int i=0; i<ch.length(); i++){	// ch�� ���� �ϳ��ϳ��� Ž�� 
		if( ch[i]=='(' ){
			st.push('(');		// (�� ������ ���ÿ� �ְ� 
		}
		else if( ch[i]==')' ){
			if( !st.empty() )	// )�� ������ ������ ���� ���� �� pop�Ѵ�. 
				st.pop();
			else
				return false;
				// )�� �����µ� ������ ����ִٸ� ���� (�� ���ٴ� ��.
				// ����� false�̴�. 
		}
	}
	bool flag = st.empty();			// flag�� ����� ���� 
	while(!st.empty())st.pop();		// ���� ���̽��� ���� ������ ������Ѵ� 
	return flag;
}

int main(){
	cin>>T;
	for(int i=0; i<T; i++){
		// ��ȣ ���ڿ��� �Է¹޴´�. 
		cin>>ch;
		if( vps(ch) ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
} 
