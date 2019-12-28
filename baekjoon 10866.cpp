#include <iostream>
using namespace std;

typedef class dequeue{
	private:
	const int f=0;		// 데이터 들어있는 제일 앞 위치 가리킴 
	int b =0;		// 데이터가 들어있는 제일 뒤 다음자리 가리킴 
	int data[10000];
	public:
	void push_front(int x){
		if( b==0 ){
			data[0] = x;
			b = 1;
		}
		else{
			// 한칸씩 데이터 밀고 
			for(int i=b; i>f; i--){
				data[i] = data[i-1];
			}
			data[0] = x;
			b++;
		}
	}
	void push_back(int x){
		if( b==0 ){
			data[0] = x;
			b=1;
		}
		else{
			data[b] = x;
			b++;
		}
	} 
	void pop_front(){
		if( b==0 ){
			cout<<-1<<'\n';
			return;
		}
		else{
			cout<<data[f]<<'\n';
			for(int i=f; i<b; i++){
				data[i] = data[i+1];
			}
			b--;
		}
	}
	void pop_back(){
		if( b==0 ){
			cout<<-1<<'\n';
		}
		else{
			cout<<data[b-1]<<'\n';
			b--;
		}
	}
	void size(){
		cout<<b<<'\n';
	}
	void empty(){
		if( b==0 ) cout<<"1\n";
		else cout<<"0\n";
	}
	void front(){
		if( b==0 ) cout<<"-1\n";
		else cout<<data[f]<<'\n';
	}
	void back(){
		if( b==0 ) cout<<"-1\n";
		else cout<<data[b-1]<<'\n';
	}
}dequeue;
int main(){
	dequeue dq;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		if( s=="push_front" ){
			int x;
			cin>>x;
			dq.push_front(x);
		}else if( s=="push_back" ){
			int x;
			cin>>x;
			dq.push_back(x);
		}else if( s=="pop_front" ){
			dq.pop_front();
		}else if( s=="pop_back"){
			dq.pop_back();
		}else if( s=="size"){
			dq.size();
		}else if( s=="empty"){
			dq.empty();
		}else if( s=="front"){
			dq.front();
		}else if( s=="back"){
			dq.back();
		}
	}
	return 0;
}
