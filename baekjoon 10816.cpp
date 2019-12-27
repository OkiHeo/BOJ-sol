#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int> > card;

int bsearch(int x){
	int start = 0;
	int end = card.size();
	int mid;
	while( start <= end ){
		mid = (start+end)/2;
		if( card[mid].first < x){
			start = mid+1;
		}
		else if( card[mid].first > x){
			end = mid-1;
		}
		else{
			// card[mid].first==x
			return card[mid].second; 
		}
	}
	// x�� ������ ī�带 ã�� �� ������
	return 0; 
}

int main(){
	scanf("%d", &n);
	vector<int> nums;
	for(int num=0; num<n; num++){
		int x;
		scanf("%d", &x);
		nums.push_back(x);
	}
	// �������ִ� ī��� ī�忡 ���� �� �������� ������������ 
	sort(nums.begin(), nums.end());
	
	// �Է¹��� ī��� �ٽ� ���Ϳ� �����鼭 ���� ����. 
	card.push_back(make_pair(nums[0],1));
	int index =0;
	for(int i=1; i<n; i++){
		if( nums[i]==card[index].first){
			card[index].second++;
		}
		else{
			card.push_back(make_pair(nums[i], 1));
			index++;
		}
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		int x;
		scanf("%d", &x);
		printf("%d ", bsearch(x));
	} 
	return 0; 
} 
