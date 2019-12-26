#include <iostream>
#include <stack>
using namespace std;

int n;
int a[1000001];			// �ε��� 1~1,000,000�� ����Ѵ� 

int main(){
	cin>>n;
	stack<int> st;
	// ��ū���� �Ǻ��� ������ a[i]�� �����Ѵ�. 
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	// ������ �� �� �ִ� ��� ���Һ��� ū ���� ���ÿ� push 
	st.push(1000002);
	// ������ �ڿ������� ������ Ž���Ѵ�. 
	for(int i=n; i>0; i--){
		// ������ top�� ���� ���������� ���� ���� �ִٸ�
		// �� ū ���� ���ö����� pop�Ѵ�.
		// -> ���� ������ ���ʿ� �����ϴ� ���� �ֱ��� �� ū ���� ���´�. 
		if( st.top()<=a[i] ){
			while(true){
				st.pop();
				if( st.top()>a[i] ) break;
			}
		}
		// �տ��� �� �������� �����ؼ� pop���� ���� �Ŀ�
		// �ٷ� a[i]�� ��ū�� �Ǵ��� ���ؼ� else��� if���� ���.
		// ���� top�� > �������̸�
		// tmp�� a[i]���� ����. 
		// a[i]�� a[i]�� ��ū��(������ top��)�� �����ϰ�
		// tmp�� �����ص� a[i]�� ���ÿ� push�Ѵ�. 
		if( st.top()>a[i]){
			int tmp=a[i]; 
			if( st.top()==1000002 ){
				a[i] = -1;
			}
			else{
				a[i] = st.top();
			}
			st.push(tmp);
		}
	}
	
	// ������ ��ū���� ����Ѵ�. 
	for(int i=1; i<=n; i++){
		cout<<a[i]<<' ';
	}
	
	return 0;
}
