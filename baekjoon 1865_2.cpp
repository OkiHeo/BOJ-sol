#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > p[501];
int testcase, point, road, worm;
int time[501];
int INF = 2000000000;

bool travel(){
	for(int i=1; i<=point; i++){
		for(int j=1; j<=point; j++){
			for(int k=0; k<p[j].size(); k++){
				int next = p[j][k].first;
				int takes = p[j][k].second+time[j];
				
				if( time[j]!=INF && takes<time[next] ){
					if( i==point ){
						return true;
					}
					time[next] = takes;
				}
			}
		}
	}
	return false;
}

int main(){
	cin>>testcase;
	for(int tc=0; tc<testcase; tc++){
        // 1�� �������� �� �������� ���µ� �ɸ��� �ð� ���Ѵ�� �ʱ�ȭ 
		for(int init=0; init<501; init++){
			time[init] = INF;
		}
		// ���� �������� ������������ ���� �ð��� 0�̴�. 
		time[1] = 0;
        for(int i=0; i<501; i++){
            p[i].clear();
        }
        
        // �Է�
		cin>>point>>road>>worm;
		for(int r=0; r<road; r++){
			int s, e, t;
			cin>>s>>e>>t;
			// ���δ� �����(=������)�̴�. 
			p[s].push_back(make_pair(e, t));
			p[e].push_back(make_pair(s, t));
		}
		for(int w=0; w<worm; w++){
			int s, e, d;
			cin>>s>>e>>d;
			// ��Ȧ�� �ܹ����̴�.
			// ��Ȧ������ �ð��� �Ųٷ� �帣�Ƿ� -d�� �������ش�. 
			p[s].push_back(make_pair(e, -d));
		}
		// ���� ����Ŭ�� �����ϸ� yes
		// (���� ����Ŭ �� �ϳ����� ����ϸ� ������� ���ƿ��� ���Ű� �ȴ�.)
		if( travel() ) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
