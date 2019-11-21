#include <iostream>
#include <cstdio> 
#include <vector>
#include <utility>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector< pair<int, int> > v;
	for(int n=0; n<N; n++){
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}
	int *grade = new int[N];
	for(int i=0; i<N; i++) grade[i]=1;		// grade배열을 모두 0으로 초기화 
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if( v[i].first > v[j].first && v[i].second > v[j].second ){
				grade[j]++;
			}
			else if(v[i].first < v[j].first && v[i].second < v[j].second){
				grade[i]++;
			}	
		}
	}
	for(int i=0 ;i<N; i++){
		printf("%d ", grade[i]);
	}
	return 0;
}
