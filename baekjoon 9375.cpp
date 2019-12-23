#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tc, n;
vector<pair<string, int> > cloth;	// 옷의 종류, 그 종류 옷 개수
 
int main(){
	cin>>tc;
	while(tc--){
		//초기화
		cloth.clear();
		
		// 입력 
		cin>>n;
		for(int i=0; i<n; i++){
			string name, category;
			cin>>name>>category;
			// 옷장에 옷이 하나도 없으면 무조건 추가! 
			if( cloth.empty()){
				cloth.push_back(make_pair(category, 1));
			}
			else{
				int isin=false;
				// 옷이 하나라도 있으면, 하나하나 비교하면서
				// 새로 입력받은 옷의 종류와 같은 옷이 있는지 체크한다.
				// 있으면 그 종류의 옷 개수를 하나 늘린다. 
				for(int j=0; j<cloth.size(); j++){
					if( cloth[j].first == category ){
						cloth[j].second++;
						isin=true;		// 그 종류 옷이 있음!	
					}
				}
				// 그 종류 옷이 없으면 옷장에 옷 종류를 추가하고,
				// 그 옷 종류 옷 개수를 하나로 한다. 
				if( !isin ){
					cloth.push_back(make_pair(category, 1));
				}
			}
		}
		// -> 모든 종류 (옷 수+1)을 곱해서 누적시킨 후 1을 뺀다.
		// -1 : 모든 옷을 입지 않는 경우
		int result=1;
		for(int i=0; i<cloth.size(); i++){
			result*=(cloth[i].second+1);	
		}
		cout<<result-1<<'\n';
	}
	return 0;
}
