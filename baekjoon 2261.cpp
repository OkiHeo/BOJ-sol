#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

// 두 점간의 거리^2를 구하는 함수 
long long int distance(Point &a, Point &b){
	long long int dist = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	return dist;
}

// x좌표를 기준으로 정렬하기 위한 comp함수 
struct comp{
	bool compX;
	comp(bool b):compX(b){}
	bool operator()(Point &a, Point &b){
		return (this->compX?a.x<b.x:a.y<b.y);
	}
};

// n개의 점들 중 최단거리를 구하기 위한 함수 
long long int closestPair(vector<Point>::iterator it, int n){
	if( n==2 ){
		return distance(it[0], it[1]);
	}
	else if( n==3 ){
		return min(distance(it[0],it[1]), min(distance(it[1],it[2]), distance(it[0], it[2])));
	}
	
	// n이 3 이상일때 x좌표를 기준으로 기준선을 정한다.
	// 중간에 위치한 두 점의 x좌표의 평균값을 기준선으로 한다. 
	int line =  (it[n/2-1].x + it[n/2].x)/2;
	// line의 좌,우 중에서 최소 거리인 d를 계산한다.
	long long int d = min( closestPair(it, n/2), closestPair(it+n/2, n-n/2) );
	
	vector<Point> mid;
	mid.reserve(n);
	
	for(int i=0; i<n; i++){
		int t = line-it[i].x;
		// x좌표 차이^2이 d보다 작다면 탐색해본다. 
		if( t*t < d ){
			mid.push_back(it[i]);	// 탐색할 대상을 mid에 추가한다 
		}
	}
	
	// line에서 d미만으로 떨어져있는 점들을 y좌표 기준으로 정렬한다. 
	sort(mid.begin(), mid.end(), comp(false));
	// mid에 존재하는 점들 중 d 미만의 dist를 가진다면 d에 업데이트
	int MIDSIZE = mid.size();
	for(int i=0; i<MIDSIZE-1; i++){
		for(int j=i+1; j<MIDSIZE&&(mid[i].y-mid[j].y)*(mid[i].y-mid[j].y) < d; j++){
			d = min( d, distance(mid[i], mid[j]) );
		}
	} 
	return d;
}

int main(){
	int n;
	cin>>n;
	
	vector<Point> vp(n);
	for(vector<Point>::iterator it=vp.begin(); it!=vp.end(); it++){
		cin>> it->x >> it->y;
	}
	
	sort(vp.begin(), vp.end(), comp(true));
	cout<<closestPair(vp.begin(), n);
	return 0;
}
