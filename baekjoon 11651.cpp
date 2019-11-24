#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp( pair<int, int> a, pair<int, int> b){
	if( a.second == b.second ){
		return a.first < b.first;
	}
	return a.second<b.second;
}

int main(){
	vector< pair<int, int> > v;
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}
	
	sort(v.begin(), v.end(), comp);
	for(vector< pair<int, int> >::iterator i=v.begin(); i<v.end(); i++){
		printf("%d %d\n", i->first, i->second);
	}
	return 0;
}
