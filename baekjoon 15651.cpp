#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int visit[8];
vector<int> v;

void dfs(int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;		// ��� �Ŀ��� dfs�Լ��� �ݵ�� ������Ѿ��Ѵ� 
	}
	
	for(int i=1; i<=N; i++){
		if( visit[i]==M ) continue;	// �ִ� M������ �湮�� �� �ֵ��� 
		visit[i]++;
		v.push_back(i);
		dfs(cnt+1);
		visit[i]--;
		v.pop_back();
	}
}

int main(){
	cin>>N>>M;
	dfs(0);
	return 0;
} 
