#include <iostream>
#include <vector>
using namespace std;

string s;
int n;		// word�� ����. 
vector<string> word;
	
bool works(int idx){
	// s�� ���� �����ϸ� true�� �����Ѵ�. 
	if( idx==s.length() ){
		return true;
	}
	
	// s�� idx�������� word�� �����ϴ� �ܾ� �ϳ��ϳ��� ��Ī���Ѻ���. 
	for(int i=0; i<n; i++){
		bool flag = true;
		
		// word[i]�� ���̸� idx�� ������ �� s�� ���̸� ����� �� ���ڴ� �������ʴ´�. 
		if( idx+word[i].length() > s.length() ) continue;
		
		// s�� idx���� word[i]�� ���� �ϳ��ϳ� ���Ѵ�. 
		for(int ii=0; ii<word[i].length(); ii++){
			if( s[idx+ii] != word[i][ii] ){
				flag = false;
				break;	// �� word�� ��Ī���������Ƿ� break�ϰ� ���� ���� ��Ī���� �Ѿ��. 
			}
		}
		
		if( flag ){
			// word[i]�� s�� ������ �� �ִٸ� �� ������ s�� ���ؼ� ��������� �������� �˻��Ѵ�.
			if( works(idx+word[i].length()) ) return true;
		}
	}
	return false;
} 

int main(){
	cin>>s;
	cin>>n;
	for(int i=0; i<n; i++){
		string x;
		cin>>x;
		word.push_back(x);
	}
	
	if( works(0)==true ){
		cout<<"1\n";
	}
	else{
		cout<<"0\n";
	}
	return 0;
}
