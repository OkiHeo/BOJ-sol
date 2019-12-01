#include <iostream>
#include <cstdio>
#define STACK_SIZE 10000
using namespace std;

int N;	//명령의 개수 
typedef class stack{
	public:
		// 정수 x를 스택에 넣는 연산이다. 
		void push(int x){
			if(s_top>STACK_SIZE){
				return;
			}
			s_top++;
			s[s_top] = x;
		}
		// 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
		// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다. 
		void pop(){
			if( s_top<0 ){
				printf("-1\n");
				return;
			}
			printf("%d\n", s[s_top]);
			s_top--;
		}
		// 스택에 들어있는 정수의 개수를 출력한다. 
		void size(){
			printf("%d\n", s_top+1); 
		}
		// 스택이 비어있으면 1, 아니면 0을 출력한다. 
		void empty(){
			if( s_top<0 ){
				printf("1\n");
			}
			else printf("0\n");
		}
		// 스택의 가장 위에 있는 정수를 출력한다.
		// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다. 
		void top(){
			if( s_top<0 ){
				printf("-1\n");
			}
			else printf("%d\n", s[s_top]);
		}
	private:
		int s_top=-1;
		int s[STACK_SIZE]; 
}stack;

int main(){
	stack s;
	cin>>N;
	string command;
	int x;
	for(int i=0; i<N; i++){
		cin>>command;
		if( "push" == command ){
			cin>>x;
			s.push(x);
		}
		else if("pop"==command){
			s.pop();
		}else if("size"==command){
			s.size();
		}else if("empty"==command){
			s.empty();
		}else if("top"==command){
			s.top();
		}
	}
	return 0;
} 
