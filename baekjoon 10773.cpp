#include <iostream>
using namespace std;
 
int nums[100001];
int main(){
	int k;	// �Է¹��� ������ ���� 
	int idx=-1;
	cin>>k;
	
	// k���� �ٿ� ������ 1���� �Է¹��� 
	for(int i=0; i<k; i++){
		int tmp;
		cin>>tmp;
		// �Է¹��� ���� 0�� �ƴϸ� �ش� ���� ����. 
		if( tmp!=0 ){
			idx++;
			nums[idx]=tmp;
			continue;
		}
		// �Է¹��� ���� 0�̸� ���� �ֱٿ� �� ���� �����. 
		else{
			idx--;
			continue;
		}
	}
	
	// ���������� ���� ������ ���� ���. 
	int sum=0;
	for(int i=0; i<=idx; i++){
		sum+=nums[i];
	}
	cout<<sum<<'\n';
	return 0;
}
