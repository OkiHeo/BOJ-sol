#include <iostream>
#include <vector>
using namespace std;

int n;
int A[501];				// �ε��� 1~500�� ���. 
						// A[i]���� ����Ǿ��ִ� B�������� ��ġ��ȣ�� ���� 
int amax, bmax;
int d[501];				// A������ ����~A[i]�����ٱ��� ���������� ����Ǿ��ִ� ������ �� 

int solve(){
	// A[i]�� �������� �����ϴ�, ���������� ���������� ����� �������� ��
	for(int i=1; i<=amax; i++){
		if( A[i]==0 ) continue;	// i��ġ�� ����� ������ ������ �н�
		// A[i]������ ����� �����ٵ� Ž��.
		for(int j=1; j<=i; j++){
			// A[i]�� ����� ���� �������� ���������� ����Ǿ�� üũ�Ѵ�. 
			if( A[j]<A[i] ){
				// A[j]���� ���������� ����� �������� ���� + 1 (A[i]��° ������ �߰�) 
				d[i] = max(d[i], d[j]+1);
			}
		} 
	}
	int result=0;
	for(int i=1; i<=amax; i++){
		result = max(result, d[i]);
	}
	return n-result;
}

int main(){
	cin>>n;	//�������� ���� �Է�
	// �� ������ ������ ������ n�� �Է� 
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		amax = max(amax, a);	// �������� ����� ���� ū ������ġ ����
		A[a] = b;				// A�������� a��ġ->B�������� b��ġ ������ ���� 
		d[a] = 1;
	}
	cout<<solve();	
}
