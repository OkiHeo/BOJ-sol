#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[9];
int cnt;
vector<int> v;

void dfs(int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=N; i++){
		// �ռ� �湮�ߴ� ���ڴ� �湮x 
		if( visit[i] == true ){
			continue;
		}
		visit[i] = true;
		v.push_back(i);
		dfs(cnt+1);		//����Լ��� ������ DFS. i�� �����ϴ� ���� dfs �����Ѵ�. 
		visit[i] = false;
		v.pop_back();
	}
}
int main(){
	cin>>N>>M;
	// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ���� ��� ���.
	dfs(0);
	return 0;
}
