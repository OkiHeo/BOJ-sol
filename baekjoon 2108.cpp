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
	vector< pair<int, int> > count;		// 값, 빈도 저장할 배열 0으로 초기화 
	for(int i=0; i<N; i++){
		if(count.empty()){
			count.push_back(pair<int, int>(arr[i], 1));
			continue;	
		}
		if(count.back().first == arr[i]){		// arr이 순서대로 정렬되어있으므로 가능하다. 
			pair<int, int> tmp = count.back();
			tmp.second++;
			count.pop_back();
			count.push_back(tmp);
		}
		else{
			count.push_back(pair<int, int>(arr[i], 1));
		}
	}
	// '1순위 : 빈도, 2순위 : 값 작은 순서'로 정렬
	sort(count.begin(), count.end(), comp );
	
	if( count[0].second == count[1].second){
		return count[1].first;	// 빈도수 같으면 값 더 큰것 
	}
	else{
		return count[0].first;	// 빈도수 더 큰것. 
	}
}
int main(){
	scanf("%d", &N);
	double sum=0;
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	sort(arr, arr+N);		// arr 배열을 오름차순으로 정렬 
	
	int maxcount = findmaxcount(arr, N);
	printf("%d\n", (int)floor(sum/N+0.5));	// 산술평균 출력(소수점이하 첫째자리에서 반올림) 
	printf("%d\n", arr[N/2]);			// 중앙값 출력
	printf("%d\n", maxcount);			// 최빈값 출력
	printf("%d\n", arr[N-1]-arr[0]);	// 범위 출력 
	return 0; 
} 
