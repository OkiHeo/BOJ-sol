#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;

int main(){
	cin>>s;
	vector<int> num;
	vector<char> op;
	int tmp;
	/* ���ڿ� �����ڸ� �Ľ��Ѵ�. */
	for(int i=0; i<s.length(); i++){
		tmp=0;
		// ������ ��� 
		if( s[i]!='+' && s[i]!='-' ){
			if(i-1>=0 && s[i-1]!='+' && s[i-1]!='-'){	// ���� ��ġ�� ���ڿ��ٸ� �����ؾ��ϴϱ�. 
				tmp = num.back();	// ���� �ֱ� ���� ���Ϳ��� ������ 
				num.pop_back();		// ���� �ֱ� ���� ���Ϳ��� ���� 
				tmp = tmp*10; 		// ���ڸ��� �ø���. 
			}
			tmp += static_cast<int>(s[i]-'0');
			num.push_back(tmp);		// ���Ϳ� ����. 
		}
		// �������� ��� 
		else{
			op.push_back(s[i]);
		}
	}
	/* �� �Ľ̵ƴ��� Ȯ���ϴ� �κ�. */
	for(int i=0; i<num.size(); i++){
		cout<<num[i]<<' '; }
	cout<<'\n';
	for(int i=0; i<op.size(); i++){
		cout<<op[i]<<' '; }
	
	/* ���� ����� �����ϴ� �κ� */
	// �ִ��� ���� ����, ���� ���Ѵ�.
	// -�� ������ �������� ��� ���ڸ� �����ش�. 
	// == -�� ������ ���� ���ڵ��� ��� ���ش�. 
	// '-' ���Ŀ� ��Ÿ���� '+'���� -(a+b+c)-(d+e) �� ���� ��� -�� �ٲ� �� �����Ƿ� 
	tmp = 0;	// tmp�� ��� ��� ��������� ��Ȱ������. 
	for(int i=0, j=0; i<num.size()&&j<op.size(); ){
		tmp = num[i];
		if( op[j]=='-' ){
			while(j!=op.size()){
				tmp-=num[++i];
				j++;	
			}
			break;
		}
		else if( op[j]=='+'){
			tmp+=num[++i];
			j++;
		}
	}
	cout<<"result: "<<tmp<<'\n';
	return 0;
}
