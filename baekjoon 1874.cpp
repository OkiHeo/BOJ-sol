#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int nums[100000];
// c/c++������ a[100000] ũ���� �迭�� ���������� ������ �� ���ٰ��ؼ� ���������� ���� 
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>nums[i];		// �ε��� 1~n ��� 
	}
	
	// 1~n�� ������ ������
	// ���ÿ� push �ϴ� ������ �ݵ�� ���������� ��Ų��
	// ������ ������ ������ �̿��� �� ������ ���� �� ������push/pop���� ����ؼ� ǥ���ϰ�
	// ����������� NO�� ����Ѵ�.
	stack<int> st;
	queue<char> q;
	int i=1, j=0;
	
	while( j<n ){
		// ������ ��������ʰ� top==nums[j]�϶� 
		while( !st.empty() && st.top() == nums[j] ){
			st.pop();
			q.push('-');
			j++;
		}
		// nums[j]������ ��(i)�� ���ÿ� push�Ѵ�.
		if( nums[j]>=i ){
			while(true){
				if( nums[j]<i ) break;
				st.push(i);
				q.push('+');
				i++;	
			}
		}
		// nums[j]������ ���� �̹� ���ÿ� ���µ�
		// ������ ��������ʰ�, top�� �����ϴ� ���� nums[j]���� ũ�ٸ�
		// �� ������ ������ �̿��ؼ� ���� �� �����Ƿ� NO�� ��� 
		else if( !st.empty() && st.top()>nums[j] ){
			cout<<"NO\n";
			return 0;
		}
	}
	while(!q.empty()){
		cout<<q.front()<<'\n';
		q.pop();
	}
	return 0;
}
