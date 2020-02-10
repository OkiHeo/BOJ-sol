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
		name[i].push_back(100000000);		// upperbound����� ���� �߻��� �� �ִ� �ִ� �ε������� ū ���� �־��ش�. 
		sort(name[i].begin(), name[i].end());
		for(int j=0; j<name[i].size()-1; j++){
			// ���� ��+k ���� ���ʷ� ū �� ������ ����Ű�� iterator ���Ѵ�. 
			vector<int>::iterator iter = upper_bound(name[i].begin(), name[i].end(), name[i][j]+k);
			iter--;
			// iter�� ���� ��+k���� ���ʷ� ū ���� ������ iterator�̴�. 
			goodfriend += iter-name[i].begin()-j;
			// iter�� name[i]�� �� ��° �ε����� ��ġ�ϴ��� ���ϰ�, j�� ���ش�. 
		}
	}
	cout<<goodfriend<<'\n';
	return 0;
}
