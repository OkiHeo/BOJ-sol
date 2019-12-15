#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int> > city[501];		// city[1] ... city[500] ��� 
//city[i] -> B, time
int d[501];
int INF = 7000000;

void bellmanford(int start){
	// ���� ���� ������ �ٸ� ���÷� ���� �ð� ���Ѵ�� �ʱ�ȭ. 
	for(int i=1; i<=n; i++){
		d[i] = INF;
	}
	d[start] = 0;

	// dense graph�� �����ϰ� ��� ��尣�� ������ Ž���Ѵ�. 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<city[j].size(); k++){
				int next = city[j][k].first;
				int connect = city[j][k].second;
				
				// d[j]�� INF�� �ƴ� ������ ���� ����ġ�� ���ؼ� ������Ʈ �ϴ� ���� �ǹ��ִ�. 
				if( d[j]!=INF && d[next]>connect+d[j] ){
					// �ִ� ��θ� ã�� �� ��� ���������� �ٽ� ���ƿ� ��� 
					if( i==n ){
						cout<<"-1\n";
						return;
					}
					d[next] = connect + d[j];
				}
			}
		}
	}
	
	// 1�����ÿ��� ����ؼ� i��° ���÷� ���� �ִܰŸ� ���. 
	for(int i=2; i<=n; i++){
		if( d[i]>=5000000 ){
			cout<<"-1\n";
		}else{
			cout<<d[i]<<'\n';
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int start, dest, time;
		cin>>start>>dest>>time;
		city[start].push_back(make_pair(dest, time));
	}
	
	/* ���� ���� �˰��� ���� */
	bellmanford(1);
	return 0;
} 
