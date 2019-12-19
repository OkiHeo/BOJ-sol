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
	/* 숫자와 연산자를 파싱한다. */
	for(int i=0; i<s.length(); i++){
		tmp=0;
		// 숫자인 경우 
		if( s[i]!='+' && s[i]!='-' ){
			if(i-1>=0 && s[i-1]!='+' && s[i-1]!='-'){	// 이전 위치도 숫자였다면 연결해야하니까. 
				tmp = num.back();	// 가장 최근 숫자 벡터에서 꺼내고 
				num.pop_back();		// 가장 최근 숫자 벡터에서 삭제 
				tmp = tmp*10; 		// 한자릿수 늘린다. 
			}
			tmp += static_cast<int>(s[i]-'0');
			num.push_back(tmp);		// 벡터에 삽입. 
		}
		// 연산자인 경우 
		else{
			op.push_back(s[i]);
		}
	}
	/* 잘 파싱됐는지 확인하는 부분. */
	for(int i=0; i<num.size(); i++){
		cout<<num[i]<<' '; }
	cout<<'\n';
	for(int i=0; i<op.size(); i++){
		cout<<op[i]<<' '; }
	
	/* 실제 계산을 수행하는 부분 */
	// 최대한 많이 빼고, 적게 더한다.
	// -를 만나기 이전에는 모든 숫자를 더해준다. 
	// == -를 만나면 이후 숫자들은 모두 빼준다. 
	// '-' 이후에 나타나는 '+'들은 -(a+b+c)-(d+e) 와 같이 모두 -로 바꿀 수 있으므로 
	tmp = 0;	// tmp를 계산 결과 저장용으로 재활용하자. 
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
