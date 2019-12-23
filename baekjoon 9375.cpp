#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tc, n;
vector<pair<string, int> > cloth;	// ���� ����, �� ���� �� ����
 
int main(){
	cin>>tc;
	while(tc--){
		//�ʱ�ȭ
		cloth.clear();
		
		// �Է� 
		cin>>n;
		for(int i=0; i<n; i++){
			string name, category;
			cin>>name>>category;
			// ���忡 ���� �ϳ��� ������ ������ �߰�! 
			if( cloth.empty()){
				cloth.push_back(make_pair(category, 1));
			}
			else{
				int isin=false;
				// ���� �ϳ��� ������, �ϳ��ϳ� ���ϸ鼭
				// ���� �Է¹��� ���� ������ ���� ���� �ִ��� üũ�Ѵ�.
				// ������ �� ������ �� ������ �ϳ� �ø���. 
				for(int j=0; j<cloth.size(); j++){
					if( cloth[j].first == category ){
						cloth[j].second++;
						isin=true;		// �� ���� ���� ����!	
					}
				}
				// �� ���� ���� ������ ���忡 �� ������ �߰��ϰ�,
				// �� �� ���� �� ������ �ϳ��� �Ѵ�. 
				if( !isin ){
					cloth.push_back(make_pair(category, 1));
				}
			}
		}
		// -> ��� ���� (�� ��+1)�� ���ؼ� ������Ų �� 1�� ����.
		// -1 : ��� ���� ���� �ʴ� ���
		int result=1;
		for(int i=0; i<cloth.size(); i++){
			result*=(cloth[i].second+1);	
		}
		cout<<result-1<<'\n';
	}
	return 0;
}
