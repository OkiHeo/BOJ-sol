#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;
int count=0;

void pop(){
	dq.pop_front();
}
void right(){
	// ���� ��ȯ ȸ�� <<-
	dq.push_back(dq.front());
	dq.pop_front();
	count++;
}
void left(){
	// ���� ��ȯ ȸ�� ->>
	dq.push_front(dq.back());
	dq.pop_back();
	count++;
}

int main(){
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
		dq.push_back(i);
	
	for(int i=0; i<m; i++){
		int num;
		cin>>num;
		
		// �ٷ� front���� num�� �̾Ƴ� �� �ִٸ� �̾Ƴ���. 
		if( dq.front()==num ){
			pop();
			continue;
		}
		
		int idx=0;
		// ���� �Է¹��� num�� dq�� �� ��°�� ��ġ�ϴ��� ã�´�.
		for(int i=0; i<dq.size(); i++){
			if( dq[i]==num){
				idx=i;
				break;
			}
		}
		
		// �������� ȸ����Ű�°�, �������� ȸ����Ű�� �� ��
		// ��� ���� �� ������ ���
		if( idx <= dq.size()-idx ){
			// �տ������� ���� ���� ���� ���
			// ���� ��ȯ ȸ�� ��Ű�� front ���� ������ ã�´�. 
			while(true){
				right(); 
				if( dq.front()==num ){
					pop();
					break;
				}
			}
		}
		else{
			// �ڿ������� ���� ���� ���� ���
			// ���� ��ȯ ȸ�� ��Ű�� front ���� ������ ã�´�. 
			while(true){
				left();
				if( dq.front()==num){
					pop();
					break;
				}
			}
		}
	}
	cout<<count<<'\n';
	return 0;
	
}
