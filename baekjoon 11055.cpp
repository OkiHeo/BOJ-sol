#include <iostream>
using namespace std;

int n;
int serial[1001];
int partsum[1001];
// �ε��� 1~min(1000, n)���� ���. 

int main(){
	// �Է� �� �ʱ�ȭ 
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>serial[i];
		
	partsum[1] = serial[1];
	int partsumMax=partsum[1];
	
	// ���� �� �����ϴ� �κм����� �� ���ϱ� 
	for(int i=2; i<=n; i++){
		partsum[i] = serial[i];		// ���θ� �����ϴ� ���� ���� ���̽����� ����. 
		for(int j=1; j<=i; j++){
			if( serial[i]>serial[j] && partsum[j]+serial[i] > partsum[i]){
				partsum[i] = partsum[j] + serial[i];
			}
		}
		partsumMax = max(partsumMax, partsum[i]); 
	}
	cout<<partsumMax<<'\n';
	return 0;
}
