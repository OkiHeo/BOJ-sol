#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int com, net, cnt=0;
// ��ǻ���� ��, ���� ���� ��, 1�� ��ǻ�͸� ���� �����Ǵ� ��ǻ�� �� 
queue<int> q;		// bfs�� ��� 
vector<int> node[101];		// n�� ��ǻ��(1~100)�� ������� ���� 
bool visit[101]={ false,};	// n��(1~100) ��ǻ�� �湮���� 

void bfs(int start){
	// Ž���� ������ ��ǻ��(1��) �湮ó�� 
	q.push(start);
	visit[start]=true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		// x�� ��ǻ�Ϳ� ����Ǿ��ִ� �ڽĵ� �� �湮���� �����Ϳ� �ϳ��� �湮 
		for(int i=0; i<node[x].size(); i++){
			int tmp = node[x][i];
			if( visit[tmp]==true ) continue;
			visit[tmp]=true;
			cnt++;
			q.push(tmp);
		}
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
		
	bfs(1);	// 1�� ��ǻ�Ϳ������� Ž���� �����Ѵ�. 
	cout<<cnt;
	return 0;
}
