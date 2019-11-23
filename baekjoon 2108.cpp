#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int arr[500000];

bool comp(pair<int, int> a, pair<int, int> b){
	if( a.second == b.second ){
		return a.first < b.first;
	}
	else
		return a.second>b.second;
}

int findmaxcount(int *arr, int N){
	vector< pair<int, int> > count;		// ��, �� ������ �迭 0���� �ʱ�ȭ 
	for(int i=0; i<N; i++){
		if(count.empty()){
			count.push_back(pair<int, int>(arr[i], 1));
			continue;	
		}
		if(count.back().first == arr[i]){		// arr�� ������� ���ĵǾ������Ƿ� �����ϴ�. 
			pair<int, int> tmp = count.back();
			tmp.second++;
			count.pop_back();
			count.push_back(tmp);
		}
		else{
			count.push_back(pair<int, int>(arr[i], 1));
		}
	}
	// '1���� : ��, 2���� : �� ���� ����'�� ����
	sort(count.begin(), count.end(), comp );
	
	if( count[0].second == count[1].second){
		return count[1].first;	// �󵵼� ������ �� �� ū�� 
	}
	else{
		return count[0].first;	// �󵵼� �� ū��. 
	}
}
int main(){
	scanf("%d", &N);
	double sum=0;
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	sort(arr, arr+N);		// arr �迭�� ������������ ���� 
	
	int maxcount = findmaxcount(arr, N);
	printf("%d\n", (int)floor(sum/N+0.5));	// ������ ���(�Ҽ������� ù°�ڸ����� �ݿø�) 
	printf("%d\n", arr[N/2]);			// �߾Ӱ� ���
	printf("%d\n", maxcount);			// �ֺ� ���
	printf("%d\n", arr[N-1]-arr[0]);	// ���� ��� 
	return 0; 
} 
