#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> arr;

int main(){
	/* 테스트케이스의 개수 t (t<=100) */
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++){
		bool error = false;					// 에러 발생 여부 
		/* 수행할 함수 p가 주어짐. (1<=p의 길이<=100000)
		// R: 역순으로 변환 , D: 첫 번째 숫자를 버린다. */
		string func; cin>>func;
		/* 배열에 들어 있는 수의 개수 n이 주어짐 (0<=n<=100000) */
		int n; cin>>n;
		/* 배열의 원소 입력 ex) [1,2,3] */
		arr.erase(arr.begin(), arr.end());
		string arrinput; cin>>arrinput;
		// deque<int> arr에 숫자만 저장.
		int num=0;
		if( n!=0 ){
			for(int i=1; i<arrinput.length(); i++){
				if( '0'<=arrinput[i]&&arrinput[i]<='9'){
					num = num*10 + arrinput[i]-'0';
				}
				else{
					arr.push_back(num);
					num=0;
				}
			}
		}
		
		/* 함수를 수행 */
		bool reverse = false;	// 역순으로 처리할지? true/false 
		// 함수를 차례대로 하나씩 수행한다. 
		for(int i=0; i<func.length(); i++){
			// reverse 반전. 
			if( func[i]=='R' ){
				if(reverse==false) reverse=true;
				else reverse=false;
			}
			else if( func[i]=='D' ){
				if( arr.empty() ){		// 에러 발생을 표시하고 함수 실행 종료 
					error=true;
					break;
				}
				if( !reverse ){
					// 앞에서 하나 제거 
					arr.pop_front();
				}
				else{
					// 뒤에서 하나 제거
					arr.pop_back();
				}
			}
		}
		
		/* 함수 수행 결과를 출력한다. */
		// 에러가 발생한 경우에는 error를 출력한다. 
		// 에러발생 : 모든 연산 후에 []내에 아무것도 없을 때 == deque가 비게 되면
		if( error ){
			cout<<"error\n";
			continue;
		}
		
		if( !reverse ){
			// 순서대로 출력한다.
			cout<<'[';
			for(int i=0; i<arr.size(); i++){
				cout<<arr[i];
				if( i!=arr.size()-1 ){
					cout<<',';
				}
			}
			cout<<']'<<'\n';
		}
		else{
			// 역순으로 출력한다. 
			cout<<'[';
			for(int i=arr.size()-1; i>=0; i--){
				cout<<arr[i];
				if( i!=0 ){
					cout<<',';
				}
			}
			cout<<']'<<'\n';
		}
	} 
	return 0; 
}
