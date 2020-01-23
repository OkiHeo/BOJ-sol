#include <iostream>
#include <vector>
using namespace std;

int n, M;
vector<int> mem;
vector<int> cost;
int d[10001]; 
	// d[cost]�� cost�� �����ϴ� �ִ�� Ȯ�� ������ �޸� ũ�⸦ �����Ѵ�. 



int main(){
	// �� �� 
	cin>>n>>M;
	for(int i=0; i<n; i++){
		int m;
		cin>>m;
		mem.push_back(m);
	}
	for(int i=0; i<n; i++){
		int c;
		cin>>c;
		cost.push_back(c);
	}
	// d�迭 ���� ��� -1�� �ʱ�ȭ
	fill_n(d, 10001, -1); 
	
	// �ʿ��� �޸� M����Ʈ�� Ȯ���ϱ� ���� �� ��Ȱ��ȭ�� �ּҺ�� ���.
	for(int i=0; i<n; i++){
		int c = cost[i];
		for(int j=10000; j>=c; j--){
			if( d[j-c]==-1 ) continue;	// �������ִ� j-c�� ���ؼ��� ��� 
			d[j] = max(d[j], d[j-c]+mem[i]);
			// i��° app�� �����ϴ� ���� �������� �ʴ� ��� �� Ȯ�� �޸𸮰� �� ū ��� ����. 
		}
		if( d[c]<mem[i] ) d[c] = mem[i];
	}
	for(int i=0; i<10001; i++){
		if( d[i] >= M ){
		// ���� cost���� Ž��, ���ʷ� Ȯ�� �޸𸮰� M �̻��� ��� cost ��� 
			cout<<i<<'\n';
			return 0;
		}
	}
}
