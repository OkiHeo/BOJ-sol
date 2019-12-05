#include <iostream>
using namespace std;

int N;
int A[1001];	// N�ִ밪 1000�̹Ƿ�. �ε��� 1~1000 ���

// ���� A�� i��° ������ �����ϴ� �κ� ������ ���� ����
int d[1001]; 

int solve(){
	int result=0;
	
	for(int i=1; i<=N; i++){
		// i��° �� ������ ���� �߿��� A[i]���� ���� ���� ���� ����. 
		for(int j=1; j<i; j++){
			if( A[i] > A[j] ){
				// i��° �������� ���� ������ ����
				// = i������ A[i]���� ���� �������� ���� ������ ���� + 1 (i�����Խ�Ų��.) 
				d[i] = max( d[i], d[j]+1 );
			}
		}
		// d[i]�� �����ϸ鼭, result�� ���� ū d[i]�� �����Ѵ�. 
		result = max(result, d[i]);
	}
	return result;	// ���� �� ���������� ���̸� ����. 
}

int main(){
	// ������ ���� ���� �Է�. 
	cin>>N;
	// N���� ���� �Է�. 
	for(int i=1; i<=N; i++){
		cin>>A[i];
	}	
	fill_n(d, 1001, 1);
	cout<<solve()<<"\n";
	return 0;
} 
