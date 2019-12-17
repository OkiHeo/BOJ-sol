#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int conf_n;
vector<pair<int, int> > conf;
bool comp( pair<int,int> a, pair<int,int> b){
	// 1순위 : 회의 끝 시간 오름차순
	// 2순위 : 회의 시작 시간 오름차순 
	if( a.second==b.second){
		return a.first<b.first;
	} 
	return a.second<b.second;
}
bool comp2( pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
} 
int main(){
	cin>>conf_n;
	for(int i=1; i<=conf_n; i++){
		int start, end;
		cin>>start>>end;
		conf.push_back(make_pair(start, end));
	}
	// 회의 끝나는 시간 기준으로 오름차순 정렬 
	sort(conf.begin(), conf.end(), comp);
	int finTime = 0;
	int result=0;
	for(int i=0; i<conf_n; i++){
		// 이전회의 끝나는 시간 <= 새 회의 시작시간 
		if( finTime <= conf[i].first ){
			finTime = conf[i].second;
			result++;
		}
	}
	cout<<result<<'\n';
	return 0;
}
