#include <iostream>
#include <vector>
using namespace std;

string s;
int n;		// word의 개수. 
vector<string> word;
	
bool works(int idx){
	// s의 끝에 도달하면 true를 리턴한다. 
	if( idx==s.length() ){
		return true;
	}
	
	// s의 idx에서부터 word에 존재하는 단어 하나하나를 매칭시켜본다. 
	for(int i=0; i<n; i++){
		bool flag = true;
		
		// word[i]의 길이를 idx에 더했을 때 s의 길이를 벗어나면 이 문자는 비교하지않는다. 
		if( idx+word[i].length() > s.length() ) continue;
		
		// s의 idx부터 word[i]를 문자 하나하나 비교한다. 
		for(int ii=0; ii<word[i].length(); ii++){
			if( s[idx+ii] != word[i][ii] ){
				flag = false;
				break;	// 이 word는 매칭되지않으므로 break하고 다음 문자 매칭으로 넘어간다. 
			}
		}
		
		if( flag ){
			// word[i]로 s를 구성할 수 있다면 그 이하의 s의 대해서 재귀적으로 가능한지 검사한다.
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
