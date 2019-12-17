#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int conf_n;
vector<pair<int, int> > conf;
bool comp( pair<int,int> a, pair<int,int> b){
	// 1���� : ȸ�� �� �ð� ��������
	// 2���� : ȸ�� ���� �ð� �������� 
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
	// ȸ�� ������ �ð� �������� �������� ���� 
	sort(conf.begin(), conf.end(), comp);
	int finTime = 0;
	int result=0;
	for(int i=0; i<conf_n; i++){
		// ����ȸ�� ������ �ð� <= �� ȸ�� ���۽ð� 
		if( finTime <= conf[i].first ){
			int newconf = i+1;
			// ���� �������� ȸ�� ������, ������ �ð��� ���� ����� ȸ�� ���� 
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
