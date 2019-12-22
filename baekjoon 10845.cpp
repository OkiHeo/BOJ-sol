#include <iostream>
using namespace std;

typedef class queue{
	private:
	int qsize=-1;
	int data[10001];
	public:
	void push(int x){
		qsize++;
		data[qsize] = x;
	}
	void pop(){
		if( qsize==-1 ){
			cout<<-1<<'\n';
			return;
		}
		cout<<data[0]<<'\n';
		for(int i=1; i<=qsize; i++){
			data[i-1] = data[i];
		}
		qsize--;
	}
	void size(){
		cout<<qsize+1<<'\n';
	}
	void empty(){
		if( qsize==-1 ) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	void front(){
		if( qsize==-1){
			cout<<-1<<'\n';
			return;
		}
		cout<<data[0]<<'\n';
	}
	void back(){
		if( qsize==-1){
			cout<<-1<<'\n';
			return;
		}
		cout<<data[qsize]<<'\n';
	}
}queue; 

int main(){
	int n;
	cin>>n;
	queue q;
	// n개의 명령어 입력 
	for(int i=0; i<n; i++){
		string com;
		int num;
		cin>>com;
		if(com=="push"){
			cin>>num;
			q.push(num);
		}
		else if(com=="pop"){
			q.pop();
		}
		else if(com=="size"){
			q.size();
		}
		else if(com=="empty"){
			q.empty();
		}
		else if(com=="front"){
			q.front();
		}
		else if(com=="back"){
			q.back();
		}
	}
	return 0;
}
