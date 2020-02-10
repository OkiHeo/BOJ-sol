#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> name[21];

int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		string str;
		cin>>str;
		name[str.length()].push_back(i);
	}
	
	long long int goodfriend=0;
	for(int i=0; i<=20; i++){
		name[i].push_back(100000000);		// upperbound사용을 위해 발생할 수 있는 최대 인덱스보다 큰 값을 넣어준다. 
		sort(name[i].begin(), name[i].end());
		for(int j=0; j<name[i].size()-1; j++){
			// 현재 값+k 보다 최초로 큰 값 다음을 가리키는 iterator 구한다. 
			vector<int>::iterator iter = upper_bound(name[i].begin(), name[i].end(), name[i][j]+k);
			iter--;
			// iter는 현재 값+k보다 최초로 큰 값을 가지는 iterator이다. 
			goodfriend += iter-name[i].begin()-j;
			// iter는 name[i]의 몇 번째 인덱스에 위치하는지 구하고, j를 빼준다. 
		}
	}
	cout<<goodfriend<<'\n';
	return 0;
}
