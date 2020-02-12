#include <iostream>
using namespace std;

// ��� �л����� �Բ��ϰ���� �л� �����ؾ��ϰ�,
// ȥ���ϰ� ���� �л��� �ڱ� �ڽŸ� ������ ���� �ִ�.

int t, n, cnt=0;		// cnt : ����Ŭ�� ���ϴ�(���� �̷�) ���� ���� 
int select[100000];		// [i] : i�л��� ������ �����ߴ��� ����. 
bool visit[100000];
bool finished[100000];

void dfs(int i){
	visit[i] = true;		// �湮ǥ��
	int next = select[i];
	if( visit[next]==true ){
		// i�� ������ �л��� �湮'�ߴ�'  �л��� ��
		if( finished[next]==false ){
			// i�� ������ �л��� ���� ����Ŭ�� ���Ե��� ���� �л��� ��
			int tmp=next;
			while( tmp!=i ){
				cnt++;		// ����Ŭ�� �����ϴ� �л����� ���ʷ� �����Ѵ�. 
				tmp = select[tmp];
			}
			cnt++;		// i �ڱ� �ڽ��� ����Ŭ�� ���Խ�Ų��. 
		} 
	}
	else{
		// i�� ������ �л��� ���� �湮���� �ʾҴٸ� �湮�Ѵ�. 
		dfs(next);
	}
	finished[i] = true;
}

int main(){
	/* �׽�Ʈ���̽��� ���� T �Է� */
	cin>>t;
	for(int T=0; T<t; T++){
		/* �л��� �� n�Է�. 2<=n<=100,000 */
		cin>>n;
		// �� �л��� ������ �л��� �Է��Ѵ�. 
		for(int i=0; i<n; i++){
			int x; cin>>x;
			select[i] = x-1;		// �Է��� �ε��� 1���� �����ϵ��� �����Ƿ�. 
		}
		// visit, team �迭 �ʱ�ȭ 
		fill(visit, visit+n, false);
		fill(finished, finished+n, false);
		/* ��� ������Ʈ ������ ������ �ʴ� �л� ���� ���Ѵ�. */
		cnt=0; 
		for(int i=0; i<n; i++){
			if( visit[i]==false )
				dfs(i);
		}
		cout<<n-cnt<<'\n';
	}
	return 0;
}
