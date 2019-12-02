#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// ��ǻ���� ��, ���� ���� ��, 1�� ��ǻ�͸� ���� �����Ǵ� ��ǻ�� �� 
vector<int> node[101];		// n�� ��ǻ��(1~100)�� ������� ���� 
bool visit[101]={ false,};	// n��(1~100) ��ǻ�� �湮���� 

void dfs(int s){
	visit[s]=true;
	
	for(vector<int>::iterator i=node[s].begin(); i<node[s].end(); i++){
		if( visit[*i]==true) continue;
		visit[*i] = true;
		cnt++;
		dfs(*i);
	}
}

int main(){
	cin>>com>>net;
	for(int i=0; i<=com; i++){
		node[i].push_back(i);
	}
	
	for(int i=1; i<=net; i++){
		int a, b;
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i=1; i<=com; i++)
		sort(node[i].begin(), node[i].end());
		
	dfs(1);
	cout<<cnt;
	return 0;
}
