#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp( pair<int, string> a, pair<int, string> b){
	return a.first<b.first;
}
int main(){
	int N;
	vector< pair<int,string> > v;
	cin>>N;
	for(int i=0; i<N; i++){
		int age;
		string name;
		cin>>age>>name;
		v.push_back( pair<int,string>(age, name) );
	}
	
	stable_sort(v.begin(), v.end(), comp);
	for(vector< pair<int,string> >::iterator i=v.begin(); i<v.end(); i++){
		cout<<i->first<<' '<<i->second<<'\n';
	}
	return 0;
}
