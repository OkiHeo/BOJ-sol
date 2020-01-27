#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

// �� ������ �Ÿ�^2�� ���ϴ� �Լ� 
long long int distance(Point &a, Point &b){
	long long int dist = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	return dist;
}

// x��ǥ�� �������� �����ϱ� ���� comp�Լ� 
struct comp{
	bool compX;
	comp(bool b):compX(b){}
	bool operator()(Point &a, Point &b){
		return (this->compX?a.x<b.x:a.y<b.y);
	}
};

// n���� ���� �� �ִܰŸ��� ���ϱ� ���� �Լ� 
long long int closestPair(vector<Point>::iterator it, int n){
	if( n==2 ){
		return distance(it[0], it[1]);
	}
	else if( n==3 ){
		return min(distance(it[0],it[1]), min(distance(it[1],it[2]), distance(it[0], it[2])));
	}
	
	// n�� 3 �̻��϶� x��ǥ�� �������� ���ؼ��� ���Ѵ�.
	// �߰��� ��ġ�� �� ���� x��ǥ�� ��հ��� ���ؼ����� �Ѵ�. 
	int line =  (it[n/2-1].x + it[n/2].x)/2;
	// line�� ��,�� �߿��� �ּ� �Ÿ��� d�� ����Ѵ�.
	long long int d = min( closestPair(it, n/2), closestPair(it+n/2, n-n/2) );
	
	vector<Point> mid;
	mid.reserve(n);
	
	for(int i=0; i<n; i++){
		int t = line-it[i].x;
		// x��ǥ ����^2�� d���� �۴ٸ� Ž���غ���. 
		if( t*t < d ){
			mid.push_back(it[i]);	// Ž���� ����� mid�� �߰��Ѵ� 
		}
	}
	
	// line���� d�̸����� �������ִ� ������ y��ǥ �������� �����Ѵ�. 
	sort(mid.begin(), mid.end(), comp(false));
	// mid�� �����ϴ� ���� �� d �̸��� dist�� �����ٸ� d�� ������Ʈ
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
