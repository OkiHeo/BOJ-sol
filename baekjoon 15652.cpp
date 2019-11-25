#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int visit[9];
vector<int> v;

void dfs(int a, int cnt){
	if( cnt == M ){
		for(int i=0; i<v.size()-1; i++){
			if( v[i]>v[i+1] ) return;		//�񳻸������� ��� 
		}
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<' ';
		}
		cout<<'\n';
		return;		// ��� �Ŀ��� dfs�Լ��� �ݵ�� ������Ѿ��Ѵ� 
	}
	
	for(int i=a+1; i<=N; i++){
		if( visit[i]==M ) continue;	// �ִ� M������ �湮�� �� �ֵ��� 
		visit[i]++;
		v.push_back(i);
		dfs(a, cnt+1);
		visit[i]--;
		v.pop_back();
	}
}

int main(){
	cin>>N>>M;
	dfs(0, 0);
	return 0;
}  
