#include <iostream>
#include <cmath>
using namespace std;

int n;
int height[100001];		// 인덱스 1~n을 사용한다 
int tree[400001];	// 인덱스 1부터 시작. 

void makeTree(int node, int start, int end){
	// 구간의 최소높이가 아니라 단일원소를 가리키므로
	// 해당하는 인덱스를 저장해준다. (리프 노드) 
	if( start==end ){
		tree[node] = start;
	}
	else{
		int mid = (start+end)/2;
		// node의 자식들에 최소높이를 가지는 인덱스를 채운다! 
		makeTree(node*2, start, mid);
		makeTree(node*2+1, mid+1, end);
		
		// 현재 node기준으로 leftChild의 높이 >= rightChild의 높이 일때
		// 현재 node에는 높이 더 작은 rightChild에 저장된 인덱스를 저장. 
		if( height[tree[node*2]] >= height[tree[node*2+1]] ){
			tree[node] = tree[node*2+1];
		}
		else{
		// leftChild 높이 < rightChild높이
		// leftChild에 저장된 인덱스를 현재 node에 저장. 
			tree[node] = tree[node*2];
		}
	}
} 

int findminHeight(int start, int end, int node, int left, int right){
	// 구간 내 최소높이를 가지는 인덱스를 리턴하는 함수.
	if( left > end || right < start ){
		// 범위 바깥의 값을 원하면 return -1.(그런 값을 가지는 노드는 없음) 
		return -1;
	}
	if( left <= start && end <= right ){
		// 내가 원하는 구간 내에 현재 탐색범위가 포함되는 경우 
		// --- left ----( start ---- end )---- right --- 
		return tree[node];
	}
	
	int mid = (start+end)/2;
	int m1 = findminHeight(start, mid, node*2, left, right);
	int m2 = findminHeight(mid+1, end, node*2+1, left, right);

	if( m1==-1 ){
		return m2; 
	}else if( m2==-1 ){
		return m1;
	}
	else{
		// 높이가 더 작은 인덱스를 리턴 
		if( height[m1] <= height[m2] ){
			return m1;
		}
		else{
			return m2;
		}
	}
} 

long long int getMax(int start, int end){
	// start ~ end 구간 내의 최대넓이를 찾아서 리턴.
	
	// start-end구간 내의 최소높이를 가지는 인덱스 찾는다. 
	int hIndex = findminHeight(1, n, 1, start, end);
	// 최소높이에 대한 구간 내의 최대넓이 area에 저장. 
	long long int area = static_cast<long long int>(end-start+1)*static_cast<long long int>(height[hIndex]);
	
	// 최소높이를 가지는 인덱스 좌측에 다른 인덱스 존재하면
	// 좌측에 대해서 재귀적으로 최대넓이를 구해서 area에 최대넓이를 업데이트. 
	if( start <= hIndex-1 ){
		long long int tmpArea = getMax(start, hIndex-1);
		area = max(area, tmpArea);
	}
	
	// 최소높이를 가지는 인덱스 우측에 다른 인덱스 존재하면
	// 우측에 대해 재귀적으로 최대넓이를 구해서 area에 최대넓이를 업데이트. 
	if( hIndex+1 <=end ){
		long long int tmpArea = getMax(hIndex+1, end);
		area = max(area, tmpArea);
	}
	
	return area;
} 

int main(){
	// 0이 하나 입력될때까지 반복 
	while(true){
		cin>>n;
		if( n==0 ) return 0;
		fill_n(height, n+1, 0);		// 0으로 height를 초기화 
		for(int i=1; i<=n; i++){
			cin>>height[i];
		}	
		
		makeTree(1, 1, n);
		cout<<getMax(1, n)<<'\n'; 
	}
}
