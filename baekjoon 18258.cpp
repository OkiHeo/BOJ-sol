#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n;
	queue<int> q;
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		if( s=="push"){
			int x;
			cin>>x;
			q.push(x);
		}
		else if( s=="front"){
			cout<<q.front()<<'\n';
		}
		else if(s=="back"){
			cout<<q.back()<<'\n';
		}
		else if( s=="size"){
			cout<<q.size()<<'\n';
		}
		else if( s=="empty"){
			if( q.empty() ){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if( s=="pop"){
			if( q.empty() ){
				cout<<"-1\n";
				continue;
			}
			cout<<q.front()<<'\n';
			q.pop();
		}
	}
	return 0;
}
