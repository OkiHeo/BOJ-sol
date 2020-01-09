#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int serial[1000001];
vector<int> asc;

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>serial[i];
	}
	
	for(int i=1; i<=n; i++){
		if( asc.empty() ){
			asc.push_back(serial[i]);
			continue;
		}
		else{
			if( asc.back() < serial[i] ){
				asc.push_back(serial[i]);
				continue;
			}
			else{
				vector<int>::iterator iter = lower_bound(asc.begin(), asc.end(), serial[i]);
				*iter = serial[i];
				// asc���� serial[i]���� ���ʷ� ū ���Ҹ� ã��, serial[i]�� ��ü�Ѵ�. 
				continue; 
			}
		}
	}
	cout<<asc.size()<<'\n';
	return 0;
}
