#include <iostream>
#include <cmath>
using namespace std;

int n;
int height[100001];		// �ε��� 1~n�� ����Ѵ� 
int tree[400001];	// �ε��� 1���� ����. 

void makeTree(int node, int start, int end){
	// ������ �ּҳ��̰� �ƴ϶� ���Ͽ��Ҹ� ����Ű�Ƿ�
	// �ش��ϴ� �ε����� �������ش�. (���� ���) 
	if( start==end ){
		tree[node] = start;
	}
	else{
		int mid = (start+end)/2;
		// node�� �ڽĵ鿡 �ּҳ��̸� ������ �ε����� ä���! 
		makeTree(node*2, start, mid);
		makeTree(node*2+1, mid+1, end);
		
		// ���� node�������� leftChild�� ���� >= rightChild�� ���� �϶�
		// ���� node���� ���� �� ���� rightChild�� ����� �ε����� ����. 
		if( height[tree[node*2]] >= height[tree[node*2+1]] ){
			tree[node] = tree[node*2+1];
		}
		else{
		// leftChild ���� < rightChild����
		// leftChild�� ����� �ε����� ���� node�� ����. 
			tree[node] = tree[node*2];
		}
	}
} 

int findminHeight(int start, int end, int node, int left, int right){
	// ���� �� �ּҳ��̸� ������ �ε����� �����ϴ� �Լ�.
	if( left > end || right < start ){
		// ���� �ٱ��� ���� ���ϸ� return -1.(�׷� ���� ������ ���� ����) 
		return -1;
	}
	if( left <= start && end <= right ){
		// ���� ���ϴ� ���� ���� ���� Ž�������� ���ԵǴ� ��� 
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
		// ���̰� �� ���� �ε����� ���� 
		if( height[m1] <= height[m2] ){
			return m1;
		}
		else{
			return m2;
		}
	}
} 

long long int getMax(int start, int end){
	// start ~ end ���� ���� �ִ���̸� ã�Ƽ� ����.
	
	// start-end���� ���� �ּҳ��̸� ������ �ε��� ã�´�. 
	int hIndex = findminHeight(1, n, 1, start, end);
	// �ּҳ��̿� ���� ���� ���� �ִ���� area�� ����. 
	long long int area = static_cast<long long int>(end-start+1)*static_cast<long long int>(height[hIndex]);
	
	// �ּҳ��̸� ������ �ε��� ������ �ٸ� �ε��� �����ϸ�
	// ������ ���ؼ� ��������� �ִ���̸� ���ؼ� area�� �ִ���̸� ������Ʈ. 
	if( start <= hIndex-1 ){
		long long int tmpArea = getMax(start, hIndex-1);
		area = max(area, tmpArea);
	}
	
	// �ּҳ��̸� ������ �ε��� ������ �ٸ� �ε��� �����ϸ�
	// ������ ���� ��������� �ִ���̸� ���ؼ� area�� �ִ���̸� ������Ʈ. 
	if( hIndex+1 <=end ){
		long long int tmpArea = getMax(hIndex+1, end);
		area = max(area, tmpArea);
	}
	
	return area;
} 

int main(){
	// 0�� �ϳ� �Էµɶ����� �ݺ� 
	while(true){
		cin>>n;
		if( n==0 ) return 0;
		fill_n(height, n+1, 0);		// 0���� height�� �ʱ�ȭ 
		for(int i=1; i<=n; i++){
			cin>>height[i];
		}	
		
		makeTree(1, 1, n);
		cout<<getMax(1, n)<<'\n'; 
	}
}
