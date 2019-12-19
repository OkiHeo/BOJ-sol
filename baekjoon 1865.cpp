#include <iostream>
#include <vector>
using namespace std;

int tc, n, m, w;
int INF = 987654321;
int s[501];		// s[i]�� ���� �ִܽð� ���� 
vector<pair<int,int> > p[501];
bool flag;		// ���� ����Ŭ �߻� ���� 

int main(){
	cin>>tc;
	while(tc--){
		// ���� ����Ŭ �߻�����, ����, ��Ȧ �����, s�迭�� �ʱ�ȭ���ش�. 
		flag = false;
		for(int i=0; i<501; i++)
			p[i].clear();
		fill_n(s, n, INF);
		s[1] = 0;
		
		// ����, ����, ��Ȧ ���� �Է� 
		cin>>n>>m>>w;
		// m�� ���� �Է�. �����. 
		for(int i=0; i<m; i++){
			int s, e, t;
			cin>>s>>e>>t;
			p[s].push_back(make_pair(e, t));
			p[e].push_back(make_pair(s, t));
		}
		// w�� ��Ȧ �Է�. �ܹ���. ���� ����ġ.
		for(int i=0; i<w; i++){
			int s, e, t;
			cin>>s>>e>>t;
			p[s].push_back(make_pair(e, -t));
		}
		
		// ���� ���� �˰����� O(V*E)�̴�. 
		// ���� ���� (V) 
		for(int i=1; i<=n; i++){
		// * ����, ��Ȧ ����(E) 
			for(int j=1; j<=n; j++){
				for(int k=0; k<p[j].size(); k++){
					int next = p[j][k].first;
					int cost = p[j][k].second;
					if( s[j]!=INF && s[next]>cost+s[j]){
						s[next] = cost + s[j];
						if( i==n ){
							// ���� ����Ŭ �߻��� flag�� true�� �Ѵ�. 
							flag = true;
						}
					}
				}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
