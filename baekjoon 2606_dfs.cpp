#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// ��ǻ���� ��, ���� ���� ��, 1�� ��ǻ�͸� ���� �����Ǵ� ��ǻ�� �� 
vector<int> node[101];		// n�� ��ǻ��(1~100)�� ������� ���� 
bool visit[101]={ false,};	// n��(1~100) ��ǻ�� �湮���� 

void dfs(int s){
	visit[s]=true;		// �Ű������� �־��� ��ǻ�� �湮ó�� 
	
	// s�� ����Ǿ��ִ� ��ǻ�� �� �湮���� ���� ��ǻ�� �湮
	for(vector<int>::iterator i=node[s].begin(); i<node[s].end(); i++){
		if( visit[*i]==true) continue;
		visit[*i] = true;
		cnt++;
		dfs(*i);		// ����Ǿ��ִ� ��ǻ�Ϳ� ����� ��ǻ�� ��������� �湮 
	}
}

int main(){
	cin>>com>>net;
	
	// ��ǻ�͸� �մ� ��Ʈ��ũ ���� �Է¹޴´�. 
	for(int i=1; i<=net; i++){
		int a, b;
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	// �� ��ǻ�Ϳ� ����� ��Ʈ��ũ�� ������� ���� 
	for(int i=1; i<=com; i++)
		sort(node[i].begin(), node[i].end());
		
	dfs(1);	// 1�� ��ǻ�Ϳ������� Ž���� �����Ѵ�. 
	cout<<cnt;
	return 0;
}
