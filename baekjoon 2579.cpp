#include <iostream>
using namespace std;

int n;
int arr[301];	// ��ܿ� ���� �ִ� ���� ����. �ε��� 1~300��� 
int sums[301][3];	// [i][1]�� ������ 1ĭ �̵�, [i][2]�� ������ 2ĭ �̵� 

int stair(int n){
	// ù��° ������� �̵��ϴ°��� 1ĭ�� �̵��ϴ°�, 2ĭ�� �̵��ϴ� �� �����ϴ�. 
	sums[1][1]=sums[1][2] =arr[1];
	for(int i=2; i<=n; i++){
		// ������ 1ĭ �̵� -> ������ 2ĭ �̵��ؾ��� 
		sums[i][1] = sums[i-1][2]+arr[i];
		// ������ 2ĭ �̵� -> 1ĭ �̵�, 2ĭ �̵� ��� ����. �ִ񰪵Ǵ��������� ���� 
		sums[i][2] = max( sums[i-2][1], sums[i-2][2] ) + arr[i];
	}
	return max(sums[n][1], sums[n][2]); 
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	cout<<stair(n)<<'\n';
	return 0;
} 
