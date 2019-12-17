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
			int newconf = i+1;
			// 지금 진행중인 회의 다음에, 끝나는 시간이 가장 가까운 회의 선정 
			while( (newconf<conf_n)&&(conf[i].second>=conf[newconf].second)){
				newconf++;				
			}
			sort(conf.begin()+i, conf.begin()+newconf, comp2);
			finTime = conf[i].second;
			result++;
		}
	}
	cout<<result<<'\n';
	return 0;
}
