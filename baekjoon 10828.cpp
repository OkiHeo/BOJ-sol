#include <iostream>
#include <cstdio>
#define STACK_SIZE 10000
using namespace std;

int N;	//����� ���� 
typedef class stack{
	public:
		// ���� x�� ���ÿ� �ִ� �����̴�. 
		void push(int x){
			if(s_top>STACK_SIZE){
				return;
			}
			s_top++;
			s[s_top] = x;
		}
		// ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.
		// ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�. 
		void pop(){
			if( s_top<0 ){
				printf("-1\n");
				return;
			}
			printf("%d\n", s[s_top]);
			s_top--;
		}
		// ���ÿ� ����ִ� ������ ������ ����Ѵ�. 
		void size(){
			printf("%d\n", s_top+1); 
		}
		// ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�. 
		void empty(){
			if( s_top<0 ){
				printf("1\n");
			}
			else printf("0\n");
		}
		// ������ ���� ���� �ִ� ������ ����Ѵ�.
		// ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�. 
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
