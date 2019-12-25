#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *nums = new int[n+1];
	for(int i=1; i<=n; i++){
		cin>>nums[i];		// �ε��� 1~n ��� 
	}
	
	// 1~n�� ������ ������
	// ���ÿ� push �ϴ� ������ �ݵ�� ���������� ��Ų��
	// ������ ������ ������ �̿��� �� ������ ���� �� ������push/pop���� ����ؼ� ǥ���ϰ�
	// ����������� NO�� ����Ѵ�.
	stack<int> st;
	queue<char> q;
	int i=1, j=1;
	while(i!=n && j!=n){
		// ������ ������� �ʰ�,
		// nums[j]�� ������ �� ���� �ִ� ���� ���ٸ� pop 
		if( i>nums[j] ){
			if( nums[j] < st.top() ){
				cout<<"NO\n";
				return 0;
			}
			while( !st.empty() && nums[j]==st.top() ){
				st.pop();
				q.push('-');
				j++;
			}
		}
		// ���ÿ� nums[j]�� �ش��ϴ� ������ push�Ѵ�. 
		if( i<nums[j] )
		while(true){
			if( nums[j]<i ) break;
			st.push(i);
			q.push('+');
			i++;
		}
	}
	while(!q.empty()){
		cout<<q.front()<<'\n';
		q.pop();
	}
	return 0;
}
